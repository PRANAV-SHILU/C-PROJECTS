#include <stdio.h>
#include <string.h>

// for masking password
// #include<unistd.h>
// #include<termios.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH], password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

int login();
void register_user();
void fix_fgets_input(char *);
void input_credentials(char *username, char *password);

int main()
{
    int option;
    int user_index;

    while (1)
    {
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar(); // consume extra enter

        switch (option)
        {
        case 1:
            register_user();
            break;
        case 2:
            user_index = login();
            if (user_index >= 0)
                printf("Login successfull! Welcome %s.\n", users[user_index].username);
            else
                printf("Login failed! incorrect username or password.\n");
            break;
        case 3:
            printf("Exiting user program...\n\n");
            return 0;
        default:
            printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void register_user()
{
    if (user_count == MAX_USERS)
    {
        printf("Maximum %d users are allowed! No more registrations are Allowed!!!\n", MAX_USERS);
        return;
    }

    printf("\nRegister a new user");

    input_credentials(users[user_count].username, users[user_count].password);

    printf("Registration Successful!\n");

    user_count++;
}

int login()
{
    int i;
    char temp_username[CREDENTIAL_LENGTH], temp_password[CREDENTIAL_LENGTH];
    printf("\nLogin a user");

    input_credentials(temp_username, temp_password);

    for (i = 0; i < user_count; i++)
    {
        if (strcmp(temp_username, users[i].username) == 0 && strcmp(temp_password, users[i].password) == 0)
            return i;
    }
    return -1;
}

void input_credentials(char *username, char *password)
{
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter password (masking enabled): ");
    fflush(stdout);

    // remove entire if part
#ifdef _WIN32
    int ch;
    int i = 0;
    while ((ch = _getch()) != '\r' && ch != '\n' && ch != EOF)
    {
        // 127 is a ASCII value for DELETE
        if (ch == 8 || ch == 127)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (i < CREDENTIAL_LENGTH - 1)
        {
            password[i++] = (char)ch;
            putchar('*');
        }
    }
    password[i] = '\0';
    putchar('\n'); // not needed
#else
    struct termios old_props, new_props;
    if (tcgetattr(STDIN_FILENO, &old_props) == 0) // remove if keyword and remove ==0
    {
        new_props = old_props;
        new_props.c_lflag &= ~(ECHO | ICANON); // remove `&` sign and test if works properly
        tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

        int ch;
        int i = 0;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (ch == 8 || ch == 127) // '\b' instead of 8
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (i < CREDENTIAL_LENGTH - 1) // use just else
            {
                password[i++] = (char)ch; // remove typecast if not needed
                putchar('*');             // use printf
            }
        }
        password[i] = '\0';
        putchar('\n');

        tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
    }
    else // remove entire else part
    {
        /* fallback if tcgetattr fails */
        if (fgets(password, CREDENTIAL_LENGTH, stdin) == NULL)
            password[0] = '\0';
        fix_fgets_input(password);
    }
#endif
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

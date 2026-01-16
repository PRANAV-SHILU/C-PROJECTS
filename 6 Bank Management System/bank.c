/**
 * The below code implements a simple Bank Management System in C allowing users to create accounts,
 * deposit and withdraw amounts, check balances, and exit the system.
 * 
 * It uses file handling to store account information persistently in a binary file named "account.dat".
 * Each account is represented by a structure containing account number, name, and balance.
 * The system provides a menu-driven interface for user interaction.
 */
#include <stdio.h>
#include <string.h>

typedef struct
{
    int acc_no;
    char name[50];
    float balance;
} Account;

const char *FILENAME = "account.dat";

void createAccount()
{
    FILE *file = fopen(FILENAME, "ab+");
    // ab+ mode opens binary file for both reading and appending.
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    Account acc;
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);

    printf("\nCreate a new account...\n");
    printf("Enter name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int ind = strcspn(acc.name, "\n");
    acc.name[ind] = '\0';
    printf("Enter account number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
}

void depositAmount()
{
    printf("\nDeposite amount...\n");
    FILE *file = fopen(FILENAME, "rb+");
    // rb+ mode opens binary file for both reading and writing.
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    Account acc_read;
    int acc_no;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc_read.balance += amount;

            fseek(file, -(long)sizeof(acc_read), SEEK_CUR);
            // Move file pointer back to the start of the structure record to update it. SEEK_CUR is used to set the position relative to current position.
            fwrite(&acc_read, sizeof(acc_read), 1, file);
            printf("Rs. %.2f Amount deposited successfully! New Balance: %.2f\n", amount, acc_read.balance);
            fclose(file);
            return;
        }
    }

    printf("Account no %d was not found!\n", acc_no);
    fclose(file);
}

void withdrawAmount()
{
    printf("\nWithdraw amount...\n");
    FILE *file = fopen(FILENAME, "rb+");
    // rb+ mode opens binary file for both reading and writing.
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    Account acc_read;
    int acc_no;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_no);
    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > acc_read.balance)
            {
                printf("Insufficient balance! Current Balance: %.2f\n", acc_read.balance);
            }
            else
            {
                acc_read.balance -= amount;

                fseek(file, -(long)sizeof(acc_read), SEEK_CUR);
                fwrite(&acc_read, sizeof(acc_read), 1, file);
                printf("Rs. %.2f Amount withdrawn successfully! New Balance: %.2f\n", amount, acc_read.balance);
            }
            fclose(file);
            return;
        }
    }
    printf("Account no %d was not found!\n", acc_no);
}

void balanceEnquiry()
{
    printf("\nBalance Enquiry...\n");

    FILE *file = fopen(FILENAME, "rb");
    // rb mode opens binary file for reading.
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    Account acc_read;
    int acc_no;
    printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("\nAccount Number: %d", acc_read.acc_no);
            printf("\nAccount Holder Name: %s", acc_read.name);
            printf("\nAccount Balance: %.2f\n", acc_read.balance);
            fclose(file);
            return;
        }
    }
    printf("Account no %d was not found!\n", acc_no);
    fclose(file);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n*** Welcome to the Bank Management System ***");
        printf("\n1. Create Account");
        printf("\n2. Deposit Amount");
        printf("\n3. Withdraw Amount");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");
        printf("\n\nSelect Your Option (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositAmount();
            break;
        case 3:
            withdrawAmount();
            break;
        case 4:
            balanceEnquiry();
            break;
        case 5:
            printf("Thank you for using the Bank Management System. Goodbye!\n\n");
            return 0;

        default:
            printf("Invalid choice! Please select a valid option.");
            break;
        }
    }
}
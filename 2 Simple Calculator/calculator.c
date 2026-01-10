/**
 * The below function is a simple calculator program in C that allows users to perform basic arithmetic
 * operations on two numbers.
 */
#include <stdio.h>
#include <math.h>
void display_menu()
{
    printf("--------------------------------\n");
    printf("Simple Calculator Menu:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Power (^)\n");
    printf("7. Exit\n");
    printf("Enter your choice : ");
}

int main()
{
    int choice;
    double num1, num2, result;

    printf("\nWelcome to Simple Calculator!\n");

    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        if (choice == 7)
            break;

        if (choice < 1 || choice > 7)
        {
            fprintf(stderr, "\nInvalid choice! Please try again.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("now, Enter second number: ");
        scanf("%lf", &num2);

        switch (choice)
        {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 != 0)
                result = num1 / num2;
            else
            {
                fprintf(stderr, "\nError! Division by zero.\n");
                result = NAN;
            }
            break;
        case 5:
            if (num2 != 0)
                result = fmod(num1, num2);
            // result = (int)num1 % (int)num2;
            else
            {
                fprintf(stderr, "\nError! modulus by zero.\n");
                result = NAN;
            }
            break;
        case 6:
            result = pow(num1, num2);
            break;
        default:
            printf("\nInvalid choice!\n");
        }

        if (!isnan(result))
            printf("\nResult of above operation is : %.2lf\n", result);
    }

    printf("\nThank you for using Simple Calculator!\n\n");
    return 0;
}
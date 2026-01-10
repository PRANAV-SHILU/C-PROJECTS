#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int random, guess, attempts = 0;
    srand(time(NULL));

    printf("\nWelcome to the Number Guessing Game!\n");
    random = rand() % 100 + 1; // Random number between 1 and 100
    do
    {
        printf("\nEnter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        if (guess < random)
        {
            printf("Guess a larger number. \n");
        }
        else if (guess > random)
        {
            printf("Guess a smaller number. \n");
        }
        else
        {
            printf("\nCongratulations! You've guessed the number %d in %d attempts.\n", random, attempts);
        }
    } while (guess != random);

    printf("\nThank you for playing!\n");
    printf("Developed by Pranav Shilu\n\n");

    return 0;
}
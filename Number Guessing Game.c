#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printWelcomeMessage()
{
    printf("\n=======================================\n");
    printf("    Welcome to the World of Guessing!   \n");
    printf("=======================================\n");
    printf("Your task is simple: Guess the number between 1 and 100.\n");
    printf("I will guide you with hints. Good luck!\n\n");
}
int main()
{
    int target, guess, attempts = 0;
    srand(time(0));
    target = rand() % 100 + 1;
    printWelcomeMessage();
    do
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        if (guess < 1 || guess > 100)
        {
            printf("Invalid input! Please guess a number between 1 and 100.\n\n");
        }
        else if (guess < target)
        {
            printf("Too low! Try guessing a larger number.\n\n");
        }
        else if (guess > target)
        {
            printf("Too high! Try guessing a smaller number.\n\n");
        }
        else
        {
            printf("\nCongratulations! You've guessed the number %d correctly!\n", target);
            printf("It took you %d attempts. Great job!\n\n", attempts);
        }
    }
    while (guess != target);
    printf("Thank you for playing the Guessing Game. Goodbye!\n");
    return 0;
}

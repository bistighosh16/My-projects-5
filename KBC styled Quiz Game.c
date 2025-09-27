#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
void displayQuestion(int q_num)
{
    switch (q_num)
    {
    case 1:
        printf("\nQ1: What is the capital of France?\n");
        printf("A. Berlin\nB. Madrid\nC. Paris\nD. Rome\n");
        break;
    case 2:
        printf("\nQ2: Which programming language is known as the mother of all languages?\n");
        printf("A. C\nB. Assembly\nC. Python\nD. Java\n");
        break;
    case 3:
        printf("\nQ3: Who developed the theory of relativity?\n");
        printf("A. Isaac Newton\nB. Albert Einstein\nC. Nikola Tesla\nD. Galileo Galilei\n");
        break;
    }
}
void startTimerAndGetAnswer(int seconds, char *answer)
{
    int timeLeft = seconds;
    *answer = 0;
    while (timeLeft > 0)
    {
        if (_kbhit())
        {
            *answer = _getch();
            break;
        }
        printf("\nTime left: %d seconds     ", timeLeft);
        fflush(stdout);
        sleep(1);
        timeLeft--;
    }
    if (*answer == 0)
    {
        printf("\nTime's up! No answer provided.\n");
    }
}
void giveLifelineHint(int q_num)
{
    switch (q_num)
    {
    case 1:
        printf("\nLifeline Hint: The capital of France is known as the city of lights.\n");
        break;
    case 2:
        printf("\nLifeline Hint: This programming language is still widely used in many applications.\n");
        break;
    case 3:
        printf("\nLifeline Hint: This scientist is famous for his formula E=mc^2.\n");
        break;
    }
}
int main()
{
    int questionNumber = 1;
    char userAnswer;
    char lifelineChoice;
    int score = 0;
    while (questionNumber <= 3)
    {
        system("cls");
        displayQuestion(questionNumber);
        printf("\n\nDo you want to use a lifeline? Press 1 for Yes or any other key for No: ");
        lifelineChoice = getch();
        if (lifelineChoice == '1')
        {
            giveLifelineHint(questionNumber);
            sleep(2);
        }
        printf("\n\nChoose between options A, B, C, D to answer: ");
        sleep(1);
        startTimerAndGetAnswer(30, &userAnswer);
        if (questionNumber == 1 && userAnswer == 'C')
        {
            printf("\n\033[0;32mCorrect Answer!\033[0m\n");
            score++;
        }
        else if (questionNumber == 2 && userAnswer == 'A')
        {
            printf("\n\033[0;32mCorrect Answer!\033[0m\n");
            score++;
        }
        else if (questionNumber == 3 && userAnswer == 'B')
        {
            printf("\n\033[0;32mCorrect Answer!\033[0m\n");
            score++;
        }
        else if (userAnswer != 0)
        {
            printf("\n\033[0;31mWrong Answer! The correct answer was ", userAnswer);
            if (questionNumber == 1)
            {
                printf("C. Paris\n");
            }
            else if (questionNumber == 2)
            {
                printf("A. C\n");
            }
            else if (questionNumber == 3)
            {
                printf("B. Albert Einstein\n");
            }
        }
        questionNumber++;
        sleep(2);
    }
    printf("\nGame Over\nYour final score is: %d out of 3\n", score);
    return 0;
}

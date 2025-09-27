#include <stdio.h>
void printProgressBar(float progress, int totalWidth)
{
    int completed = (int)(progress * totalWidth / 100);
    int remaining = totalWidth - completed;
    printf("[");
    for (int i = 0; i < completed; i++)
    {
        printf("#");
    }
    for (int i = 0; i < remaining; i++)
    {
        printf(" ");
    }
    printf("] %.2f%%\n", progress);
}
int main()
{
    int totalTasks;
    float progress;
    int totalWidth = 50;
    printf("Enter the total number of tasks: ");
    scanf("%d", &totalTasks);
    for (int i = 1; i <= totalTasks; i++)
    {
        printf("Enter progress percentage for task %d (0 to 100): ", i);
        scanf("%f", &progress);
        printf("Task %d: ", i);
        printProgressBar(progress, totalWidth);
    }
    return 0;
}

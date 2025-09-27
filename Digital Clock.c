#include <stdio.h>
#include <time.h>
#include <unistd.h>
void displayTime(int format)
{
    time_t currentTime;
    struct tm *localTime;
    while (1)
    {
        time(&currentTime);
        localTime = localtime(&currentTime);
        int hours = localTime->tm_hour;
        int minutes = localTime->tm_min;
        int seconds = localTime->tm_sec;
        char *am_pm = "AM";
        if (format == 12 && hours >= 12)
        {
            am_pm = "PM";
            if (hours > 12)
            {
                hours -= 12;
            }
        }
        else if (format == 12 && hours == 0)
        {
            hours = 12;
        }
        printf("\033[H\033[J");
        printf("=================================\n");
        printf("         Digital Clock           \n");
        printf("=================================\n");
        if (format == 24)
        {
            printf("         %02d:%02d:%02d           \n", localTime->tm_hour, minutes, seconds);
        }
        else
        {
            printf("         %02d:%02d:%02d %s       \n", hours, minutes, seconds, am_pm);
        }
        printf("=================================\n");
        sleep(1);
    }
}
int main()
{
    int format;
    printf("Welcome to the Digital Clock!\n");
    printf("Choose your time format:\n");
    printf("1. 24-hour format\n");
    printf("2. 12-hour format\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &format);
    if (format == 1)
    {
        displayTime(24);
    }
    else if (format == 2)
    {
        displayTime(12);
    }
    else
    {
        printf("Invalid choice. Please restart the program and choose 1 or 2.\n");
    }
    return 0;
}

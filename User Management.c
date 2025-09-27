#include <stdio.h>
#include <string.h>
#define MAX_USERS 10
#define MAX_LENGTH 50
typedef struct
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;
User users[MAX_USERS];
int userCount = 0;
void registerUser()
{
    if (userCount >= MAX_USERS)
    {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("Username already exists. Try another one.\n");
            return;
        }
    }
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("User registered successfully!\n");
}
int loginUser()
{
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful! Welcome, %s.\n", users[i].username);
            return i;
        }
    }
    printf("Invalid username or password.\n");
    return -1;
}
void displayUserDetails(int userIndex)
{
    if (userIndex >= 0)
    {
        printf("User Details:\n");
        printf("Username: %s\n", users[userIndex].username);
    }
    else
    {
        printf("No user found.\n");
    }
}
int main()
{
    int choice;
    int loggedInUserIndex = -1;

    while (1)
    {
        printf("\nUser Management System\n");
        printf("1. Register User\n");
        printf("2. Login\n");
        printf("3. Display User Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loggedInUserIndex = loginUser();
            break;
        case 3:
            if (loggedInUserIndex != -1)
            {
                displayUserDetails(loggedInUserIndex);
            }
            else
            {
                printf("You need to log in first.\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

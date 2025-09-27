#include <stdio.h>
#include <string.h>
#define MAX_ACCOUNTS 10
#define MAX_LENGTH 50
typedef struct
{
    char name[MAX_LENGTH];
    int accountNumber;
    float balance;
} Account;
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;
void createAccount()
{
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.accountNumber = accountCount + 1000;
    newAccount.balance = 0;
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}
void depositMoney()
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount!\n");
            }
            else
            {
                accounts[i].balance += amount;
                printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}
void withdrawMoney()
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount!\n");
            }
            else if (amount > accounts[i].balance)
            {
                printf("Insufficient balance!\n");
            }
            else
            {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}
void checkBalance()
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);


    int i;
    for (i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
void displayAccountDetails()
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("\nAccount Details:\n");
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n*** Bank Management System ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            displayAccountDetails();
            break;
        case 6:
            printf("Exiting Bank Management System...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

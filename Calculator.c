#include <stdio.h>
#include <math.h>
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exp);
double square_root(double num);
long long factorial(int num);
void displayMenu();
int main()
{
    int choice;
    double num1, num2, result;
    int intNum;
    char continueCalc;
    printf("=======================================\n");
    printf("          Welcome to Calculator         \n");
    printf("=======================================\n");
    do
    {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0)
            {
                result = divide(num1, num2);
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0)
            {
                result = square_root(num1);
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Square root of a negative number is not defined.\n");
            }
            break;
        case 7:
            printf("Enter a non-negative integer: ");
            scanf("%d", &intNum);
            if (intNum >= 0)
            {
                printf("Result: %lld\n", factorial(intNum));
            }
            else
            {
                printf("Error: Factorial of a negative number is not defined.\n");
            }
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
        }
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &continueCalc);
    }
    while (continueCalc == 'y' || continueCalc == 'Y');
    printf("Thank you for using the Calculator. Goodbye!\n");
    return 0;
}
double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    return a / b;
}
double power(double base, double exp)
{
    return pow(base, exp);
}
double square_root(double num)
{
    return sqrt(num);
}
long long factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
void displayMenu()
{
    printf("\nSelect an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
}

#include <stdio.h>

int digitStore[10]; // To store each digit in a reverse order

// To find number of digits
int digitFinder(int integerNumber)
{
    short i = 10, j = 0;
    while (integerNumber > 0)
    {
        integerNumber = integerNumber / i;
        j++;
    }
    return j;
}

// To split and store each digit in a reverse order
int reverseNumber(int integerNumber, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        digitStore[i] = integerNumber % 10;
        integerNumber = integerNumber / 10;
    }
}

int main()
{
    int integerNumber, digits, temp;

    printf("Enter any integer number : ");
    scanf("%d", &integerNumber); // 652

    temp = integerNumber;
    digits = digitFinder(integerNumber);

    reverseNumber(temp, digits);

    printf("The digits of %d are : %d\n", integerNumber, digits);

    printf("The reverse of %d is ", integerNumber);

    // To print each digit stored in array
    for (int i = 0; i < digits; i++)
    {
        printf("%d", digitStore[i]);
    }
}
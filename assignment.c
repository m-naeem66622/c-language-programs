#include <stdio.h>
#define STATE 3
#define MONTH 3
int i, j;
char name[STATE][20];
int number[STATE][MONTH];
// char name[STATE][6] = {"State1", "State2", "Sate3"};
// int number[STATE][MONTH] = {{6, 5, 4}, {3, 2, 9}, {5, 3, 7}};
// FUNCTION DECLARATION
void getInputDetails(int[STATE][MONTH]);
int getTotalVisitor(int[STATE][MONTH]);
int getTotalAvg_VState(int[STATE][MONTH]);
int getHighestState_V(int[STATE][MONTH]);
int getHighestMonth_V(int[STATE][MONTH]);
int getLowestMonth_V(int[STATE][MONTH]);

void main(void)
{
    // FUNCTION CALL
    // getInputDetails(number);
    getTotalVisitor(number);
    getHighestState_V(number);
    getTotalAvg_VState(number);
    getHighestMonth_V(number);
    getLowestMonth_V(number);
}

// FUNCTION DEFINITION
// Get input for state name and no. of vistors for each month (Jan-Dec)
// void getInputDetails(int number[5][12])
void getInputDetails(int number[3][3])
{
    for (i = 0; i < STATE; ++i)
    {
        printf("\nEnter state name: ");
        scanf("%s", name[i]);
        for (j = 0; j < MONTH; ++j)
        {
            printf("Number of visitors in %s, for Month %d: ", name[i], j + 1);
            scanf("%d", &number[i][j]);
        }
    }
}

// Calculate and display the total number of visitors that came to Malaysia
// void getTotalVisitor(int number[5][12])
int getTotalVisitor(int number[3][3])
{
    int sum = 0;
    for (i = 0; i < STATE; ++i)
    {
        for (j = 0; j < MONTH; ++j)
        {
            sum += number[i][j];
        }
    }
    printf("\nTotal number of visitors in Malaysia: %d\n", sum);
}

// Calculate and display total and average of visitors in each state
// void getTotalAvg_VState(int number[5][12])
int getTotalAvg_VState(int number[3][3])
{
    int sumstate = 0;
    int avg = 0;
    for (i = 0; i < STATE; ++i)
    {
        sumstate = 0;
        for (j = 0; j < MONTH; ++j)
        {
            sumstate = sumstate + number[i][j];
        }
        // avg = sumstate/12
        avg = sumstate / 3;
        printf("\n\nTotal number of visitors that visited %s: %d", name[i], sumstate);
        printf("\nAverage number of visitors per month for %s: %d\n", name[i], avg);
    }
}

// Display the state with the highest number of visitors
// int getHighestState_V(int number[5][12])
int getHighestState_V(int number[3][3])
{
    int sumstate = 0;
    int highestOverall = 0;
    int temp = 0; // To obtain the address of the State with the highest number of visitors
    for (i = 0; i < STATE; ++i)
    {
        sumstate = 0;
        for (j = 0; j < MONTH; ++j)
        {
            sumstate = sumstate + number[i][j];
            if (sumstate > highestOverall)
            {
                highestOverall = sumstate;
                temp = i; // it is because we can't get the address of the name outside the loop
            }
        }
    }
    // for (int i = 0; i < STATE; i++) // According to requirement you had not to print the state with the highest visitors of each state.. You have to print only that state with the highest number of visitors.
    //{
    printf("\nState with highest number of visitors is %s with %d visitors.", name[temp], highestOverall);
    //}
}

// Display the month with the highest number of visitors in each state
// void getHighestMonth_V(int number[5][12])
int getHighestMonth_V(int number[3][3])
{
    i = 0;            // int i = 0, j; // why you have declared these variables again if you had already declared globally...
    int month[MONTH]; // To store the month of the state of highest number of visitors
    int highest = 0;
    int high[MONTH];
    // while (i < STATE)    //   (while loop) is used when repetition of a structure is unknown. It is a good habit for a programmer
    //   to use (while loop) for unknown repetition and (for loop) for known (specified) repetition
    for (i = 0; i < STATE; i++)
    {
        for (j = 0; j < MONTH; j++)
        {
            if (number[i][j] > highest)
            {
                highest = number[i][j];
                month[i] = j + 1; // The month number are stored in the array so we can print the month with its visitors according to the requirement
            }
        }
        high[i] = highest;
        highest = 0;
        // i++;   //   as we know in (for loop), the increment operator is part of
        //              it's syntax. So this line is no more used in the code segment
    }
    for (int i = 0; i < MONTH; i++)
    {
        printf("\nThe month %d is with highest number of visitors in %s : %d", month[i], name[i], high[i]); //   removed \n from the beginning and put it in the end for good presentation
    }
}

// Display the month with the lowest number of visitors in each state
// void getLowestMonth_V(int number[5][12])
int getLowestMonth_V(int number[3][3])
{
    i = 0;            // int i = 0, j; // why you have declared these variables again if you had already declared globally...
    int month[MONTH]; // To store the month of the state of lowest number of visitors
    int lowest = 0;
    int low[MONTH];

    for (i = 0; i < STATE; i++)
    {
        for (j = 1; j < MONTH; j++)
        {
            lowest = number[i][0];
            if (number[i][j] < lowest)
            {
                lowest = number[i][j];
                month[i] = j + 1; // The month number are stored in the array so we can print the month with its visitors according to the requirement
            }
        }
        low[i] = lowest;
    }
    for (int i = 0; i < MONTH; i++)
    {
        printf("\nThe month %d is with lowest number of visitors in %s : %d", month[i], name[i], low[i]);
    }
}
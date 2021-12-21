#include <stdio.h>
#define ROW 3
#define COL 4
int main()
{                                                                       //   variales and array initialization
    int arr[ROW][COL] = {{9, 12, 11, 10}, {7, 6, 9, 10}, {9, 3, 7, 5}}; //   initializing array
    int i, j;                                                           //   counter variables
    int highest, lowest;

    // for (int i = 0; i < ROW; i++)
    // {
    //     printf("\nEnter the numbers ROW %d : ", i + 1);
    //     for (j = 0; j < COL; j++)
    //     {
    //         scanf("%d", &arr[i][j]);
    //     }
    // }
    // to calculate the smallest value of each row
    for (i = 0; i < ROW; i++)
    {
        for (j = 1; j < COL; j++)
        {
            lowest = arr[i][0];

            if (arr[i][j] < lowest)
            {
                lowest = arr[i][j];
            }
        }
        printf("The smallest value is %d from Row %d and Col %d\n", lowest, i, j);
    }

    // to calculate the highest value of each row

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            highest = arr[i][0];
            if (arr[i][j] > highest)
            {
                highest = arr[i][j];
            }
        }
        printf("\nThe largest value is %d from Row %d and Col %d", highest, i, j);
    }
}
// printf("\n\n<------------FOR 1D ARRAY------------>\n");

// int low, high; //   to store the highest and lowest value of each row

// printf("\nEnter the numbers :");

// for (i = 0; i < COL; i++)
// {
//     scanf("%d", &arr[0][i]);
// }

// lowest = arr[0][0];
// for (i = 1; i < COL; i++)
// {
//     if (arr[0][i] < lowest)
//     {
//         lowest = arr[0][i];
//         low = i;
//     }
// }
// highest = 0;
// for (i = 0; i < COL; i++)
// {
//     if (arr[0][i] > highest)
//     {
//         highest = arr[0][i];
//         high = i;
//     }
// }

// printf("The smallest value is %d at %d\nThe largest value is %d at %d", lowest, low, highest, high);
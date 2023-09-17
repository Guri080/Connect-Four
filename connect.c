#include <stdio.h>

char arr[6][7]; // game board
char bar = '|';
//        c1    c2     c3    c4    c5    c6     c7
//         0     1     2     3     4     5      6
//    0 {(0,1),(0,3),(0,5),(0,7),(0,9),(0,11),(0,13)},
//    1 {(1,1),(1,3),(1,5),(1,7),(1,9),(1,11),(1,13)},
//    2 {(2,1),(2,3),(2,5),(2,7),(2,9),(2,11),(2,13)},
//    3 {(3,1),(3,3),(3,5),(3,7),(3,9),(3,11),(3,13)},
//    4 {(4,1),(4,3),(4,5),(4,7),(4,9),(4,11),(4,14)},
//    5 {(5,1),(5,3),(5,5),(5,7),(5,9),(5,11),(5,14)}

int checkWinner()
{
    int win = 0;
    int i = 0;
    while (i != 3)
    {
        return 1;
    }
    return 0;
}

void assignTurn(int column, int player)
{
    column--; // since th3 column is from 0-6 and user enters from 1-7
    if (column < 0 || column >= 7)
    { // checks if the column is not out of bounds
        printf("please enter a number between 1 and 7");
        return;
    }

    for (int i = 5; i >= 0; i--)
    {
        if (arr[i][column] == 0)
        { // Check if the element is initialized
            if (player == 1)
            {
                arr[i][column] = 'R';
                return;
            }
            else if (player == 2)
            {
                arr[i][column] = 'Y';
                return;
            }
        }
    }

    printf("Column is full try another one\n"); // print if the column is full
}

void printBoard()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            char element = arr[i][j];
            if (element == 0)
            {
                printf("%c", ' ');
            }
            else
            {
                printf("%c", element);
            }
            printf("%c", bar);
        }
        printf("\n");
    }
}

int main()
{
    char p1[100];
    char p2[100];
    int input;

    printf("Name of player 1: ");
    fgets(p1, sizeof(p1), stdin); // Read a line of input for player 1's name

    printf("Name of player 2: ");
    fgets(p2, sizeof(p2), stdin); // Read a line of input for player 2's name

    while (checkWinner() != 0)
    {
        printBoard();                                        // prints the board
        printf("1 is ready to play. Pick a column (1-7): "); // prompts p1 for a choice
        scanf("%d", &input);                                 // takes p1's input
        assignTurn(input, 1);                                // assigns the input in the board
        checkWinner();                                       // checks for a winner
        printBoard();
        printf("2 is read to play. Pick a colum (1-7): "); // prompts p2 for a choice
        scanf("%d", &input);                               // takes p2's input
        assignTurn(input, 2);
        checkWinner(); // checks for a winner
    }
    return 0;
}
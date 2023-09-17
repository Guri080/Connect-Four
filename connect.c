#include <stdio.h>

char arr[6][15] = {
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'}};

//           column1    column2    column3    column4     column5    column6    column7
//      0     1      2    3     4    5    6    7      8    9    10    11    12   13    14
//    0 {'|',(0,1), '|',(0,3), '|',(0,5), '|',(0,7), '|',(0,9), '|',(0,11), '|',(0,13), '|'},
//    1 {'|',(1,1), '|',(1,3), '|',(1,5), '|',(1,7), '|',(1,9), '|',(1,11), '|',(1,13), '|'},
//    2 {'|',(2,1), '|',(2,3), '|',(2,5), '|',(2,7), '|',(2,9), '|',(2,11), '|',(2,13), '|'},
//    3 {'|',(3,1), '|',(3,3), '|',(3,5), '|',(3,7), '|',(3,9), '|',(3,11), '|',(3,13), '|'},
//    4 {'|',(4,1), '|',(4,3), '|',(4,5), '|',(4,7), '|',(4,9), '|',(4,11), '|',(4,14), '|'},
//    5 {'|',(5,1), '|',(5,3), '|',(5,5), '|',(5,7), '|',(5,9), '|',(5,11), '|',(5,14), '|'}
int main()
{
    char p1[100];
    char p2[100];
    int input;
    int index = 5;

    printf("Name of player 1: ");
    fgets(p1, sizeof(p1), stdin); // Read a line of input for player 1's name

    printf("Name of player 2: ");
    fgets(p2, sizeof(p2), stdin); // Read a line of input for player 2's name

    while (winner() != 0)
    {
        printBoard();                                           // prints the board
        printf("%c is ready to play. Pick a column (1-7)", p1); // prompts p1 for a choice
        scanf("%d", input);                                     // takes p1's input
        assignTurnPlayer1(input, index);                        // assigns the input in the board
        checkWinner();                                          // checks for a winner
        printBoard();
        printf("%c is read to play. Pick a colum (1-7)", p2); // prompts p2 for a choice
        scanf("%d", input);                                   // takes p2's input
        assignTurnPlayer2(input, index);
        checkWinner(); // checks for a winner
    }
    return 0;
}

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

void printBoard(char arr[][15])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

char assignTurnPlayer1(int num, int index)
{
    if (strcmp(arr[index][num], ' ') == 0)
    {
        arr[index][num] = player[0];
    }

    return assignTurn(num, index - 1);
}

char assignTurnPlayer2(int num, int index)
{
    
}
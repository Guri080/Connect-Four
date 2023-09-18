#include <stdio.h>
#define ROWS 6
#define COLUMN 7

char arr[ROWS][COLUMN]; // game board
char bar = '|';
//        c1    c2     c3    c4    c5    c6     c7
//         0     1     2     3     4     5      6
//    0 {(0,1),(0,3),(0,5),(0,7),(0,9),(0,11),(0,13)},
//    1 {(1,1),(1,3),(1,5),(1,7),(1,9),(1,11),(1,13)},
//    2 {(2,1),(2,3),(2,5),(2,7),(2,9),(2,11),(2,13)},
//    3 {(3,1),(3,3),(3,5),(3,7),(3,9),(3,11),(3,13)},
//    4 {(4,1),(4,3),(4,5),(4,7),(4,9),(4,11),(4,14)},
//    5 {(5,1),(5,3),(5,5),(5,7),(5,9),(5,11),(5,14)}

// Function to check for a horizontal win
int checkHorizontalWin(int numTokens, char player)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMN - numTokens + 1; j++)
        {
            int won = 1;
            for (int i = 0; i < numTokens; i++)
            {
                if (arr[i][j + i] != player)
                {
                    won = 0;
                    break;
                }
            }
            if (won)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check for a vertical win
int checkVerticalWin(int numTokens, char player)
{
    for (int i = 0; i < ROWS - numTokens + 1; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            int won = 1;
            for (int i = 0; i < numTokens; i++)
            {
                if (arr[i + i][j] != player)
                {
                    won = 0;
                    break;
                }
            }
            if (won)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check for a diagonal win (both diagonals)
int checkDiagonalWin(int numTokens, char player)
{
    // Check diagonals from top-left to bottom-right
    for (int i = 0; i < ROWS - numTokens + 1; i++)
    {
        for (int j = 0; j < COLUMN - numTokens + 1; j++)
        {
            int won = 1;
            for (int i = 0; i < numTokens; i++)
            {
                if (arr[i + i][j + i] != player)
                {
                    won = 0;
                    break;
                }
            }
            if (won)
            {
                return 1;
            }
        }
    }

    for (int i = 0; i < ROWS - numTokens + 1; i++)// Check diagonals from top right to bottom left
    {
        for (int j = numTokens - 1; j < COLUMN; j++)
        {
            int won = 1;
            for (int i = 0; i < numTokens; i++)
            {
                if (arr[i + i][j - i] != player)
                {
                    won = 0;
                    break;
                }
            }
            if (won)
            {
                return 1;
            }
        }
    }
    return 0;
}

char checkWinner(int numTokens) //checks winner
{
    char players[] = {'R', 'Y'};

    for (int i = 0; i < 2; i++)
    {
        char player = players[i];
        if (checkHorizontalWin(numTokens, player) ||
            checkVerticalWin(numTokens, player) ||
            checkDiagonalWin(numTokens, player))
        {
            return player; // return the winner
        }
    }

    return 0; // No winner yet
}

void assignTurn(int column, int player)
{
    column--;                      // accounting that the column is from 0-6 and user enters from 1-7
    if (column < 0 || column >= 7) // checks if the column is not out of bounds
    {
        printf("please enter a number between 1 and 7");
        return;
    }

    for (int i = 5; i >= 0; i--)
    {
        if (arr[i][column] == 0) // checks an empty element
        {
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

void printBoard() // prints the updated baord inbetween games
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

void resetBoard()
{ // reset board to be blank
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int main()
{
    int input;
    int numTokens;
    int playAgain;

    do
    {
        resetBoard(); // Reset the game board before each new game

        printf("Enter the number of tokens to win (3, 4, or 5): "); // prompts to get number of tokens
        scanf("%d", &numTokens);

        while (checkWinner(numTokens) == 0)
        {
            printBoard();
            printf("Red is ready to play. Pick a column (1-7): "); // prompts red for input
            scanf("%d", &input);
            assignTurn(input, 1);

            int winner = checkWinner(numTokens);
            if (winner != 0)
            {
                printf("Congratulations! red wins!\n"); // red is congratulated for winning
                break;
            }

            printBoard();
            printf("Yellow is ready to play. Pick a column (1-7): "); // prompt yellow for input
            scanf("%d", &input);
            assignTurn(input, 2);

            winner = checkWinner(numTokens);
            if (winner != 0)
            {
                printf("Congratulations! Yellow wins!\n"); // red is congratulated for winning
                break;
            }
        }

        printf("Do you want to play again? (1 for yes, 0 for no): "); // prompts if user wants to play again
        scanf("%d", &playAgain);
    } while (playAgain);

    printf("Thanks for playing!\n");
    return 0;
}

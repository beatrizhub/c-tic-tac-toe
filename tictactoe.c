#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int playerScore, aiScore, col;
char board[3][3], row, player, ai;

// Function declarations
void startGame(); // Print logo and wait for enter
char selectSymbol(); // Prompt player for symbol selection (X or O)
void playGame(); // Loop for playing the game
bool rematch(); // Prompt player for a rematch ('Y' or 'N')

int main (void)
{
    // Display menu and prompt user to press enter to start
    startGame();

    // Prompt symbol selection and assign AI's symbol accordingly
    player = selectSymbol();
    ai = (player == 'X') ? 'O' : 'X';

    // Start game loop
    do
    {
        playGame();

    } while (rematch());

    return 0;
}

void logoASCII() // Print "TXC TAC TOE" ASCII art
{
    printf("██████████╗  ██╗██████╗    ████████╗█████╗ ██████╗    ████████╗██████╗███████╗\n╚══██╔══╚██╗██╔██╔════╝    ╚══██╔══██╔══████╔════╝    ╚══██╔══██╔═══████╔════╝\n   ██║   ╚███╔╝██║            ██║  █████████║            ██║  ██║   ███████╗\n   ██║   ██╔██╗██║            ██║  ██╔══████║            ██║  ██║   ████╔══╝\n   ██║  ██╔╝ ██╚██████╗       ██║  ██║  ██╚██████╗       ██║  ╚██████╔███████╗\n   ╚═╝  ╚═╝  ╚═╝╚═════╝       ╚═╝  ╚═╝  ╚═╝╚═════╝       ╚═╝   ╚═════╝╚══════╝\n");                                                                 
}

/* This function prints the logo's art and prompts the user to start the game. */
void startGame()
{
    logoASCII();
    printf("Press enter to start...");
    while (getchar() != '\n'); // Waits for player to press enter
}

/* This function prompts the user to select X or O until a    
 * valid input is made and then returns the chosen symbol. */
char selectSymbol()
{
    char symbol;
    
    do
    {
        printf("Select X or O: ");
        scanf(" %c", &symbol);
        symbol = toupper(symbol);
    } while (symbol != 'X' && symbol != 'O'); // Repeat until a valid symbol is entered

    return symbol;// Return the chosen symbol
}

/* This function resets the game board by looping through   
 * each cell and setting its value to a blank space (empty). */
void resetBoard()
{
    // Loop through each cell on the board
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' '; // Set value of current cell to space (empty)
        }
    }
}

/* This function prints the current state of the board on the console.
 * It first prints the column numbers (1-3) on the top row, and then each
 * row of the board labeled A, B, and C. It uses the board array to print
 * the values of each space on the board ('X', 'O', or ' ' (empty)). */
void printBoard()
{
    printf("  1   2   3\n"); // Print column numbers
    printf("A %c | %c | %c \n", board[0][0], board[0][1], board[0][2]); // Print first row
    printf("  ——|———|—— \n"); // Print horizontal line
    printf("B %c | %c | %c \n", board[1][0], board[1][1], board[1][2]); // Print second row
    printf("  ——|———|—— \n"); // Print horizontal line
    printf("C %c | %c | %c \n", board[2][0], board[2][1], board[2][2]); // Print third row
    printf("\n"); // Add extra line for readability
}

/* This function counts the number of empty spaces left on the board.
 * It iterates through each element of the board array, and decrements 
 * a counter variable whenever it encounters a non-empty space. */
int checkSpaces()
{
    int spaces = 9; // 3*3 board

    // Loop through each cell on the board
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                spaces--; // If the cell is not empty, decrement the spaces counter
            }
        }
    }
    return spaces; // Return the number of remaining empty spaces on the board
}

/* This function allows the player to make a move on the board.
 * It prompts the player to select a row and a column for their move,
 * checks if selected row and column are valid and if the space is empty.  
 * If it is valid and empty, it updates the board with the player's move. */
void playerMove()
{
    bool validMove = false;

    while (!validMove)
    {
        // Row move
        printf("Select row (A, B or C): ");
        scanf(" %c", &row);
        row = toupper(row) - 'A';

        // Column move
        printf("Select column (1, 2 or 3): ");
        scanf("%d", &col);
        col--;
        
        // Check if valid move
        if(board[row][col] != ' ' || col < 0 || col > 2 || row < 0 || row > 2)
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[row][col] = player;
            validMove = true;
        }
    }
}

/* This function checks if there is a winning move on the board and returns 
 * the symbol of the winner ('X' or 'O'), or a space if there is no winner. */
int checkWin()
{
    // Check row win
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Check column win
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Check top-left to bottom-right diagonal win
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    // Check top-right to bottom-left diagonal win
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' '; // No winner yet
}

/* This function allows the AI to make a move on the board, trying to win
 * if possible, otherwise attempting to block the player's winning move
 * if none of those options are available, a random move is generated. */
void aiMove()
{
    // Check for winning move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ') // Check if cell is empty
            {
                board[i][j] = ai; // Place AI's symbol in the empty cell

                if (checkWin() == ai) // Check if move results in a win
                {
                    return; // If yes, return without further processing
                }

                board[i][j] = ' '; // Undo the move
            }
        }
    }

    // Check for blocking move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ') // Check if cell is empty
            {
                board[i][j] = player; // Place player's symbol in the empty cell

                if (checkWin() == player) // Check if move results in blocking player's win
                {
                    // If yes, place AI's mark in the cell and return
                    board[i][j] = ai;
                    return; 
                }
                board[i][j] = ' '; // Undo the move
            }
        }
    }

    // Random move
    srand(time(0));

    // Generate random row and column until an empty cell is found
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
        
    board[row][col] = ai; // Place AI's mark in the random empty cell
} 

void victoryASCII() // Print "VICTORY" ASCII art
{
    printf("██╗   ████╗██████████████╗██████╗██████╗██╗   ██╗\n██║   ██████╔════╚══██╔══██╔═══████╔══██╚██╗ ██╔╝\n██║   ██████║       ██║  ██║   ████████╔╝╚████╔╝\n╚██╗ ██╔████║       ██║  ██║   ████╔══██╗ ╚██╔╝\n ╚████╔╝██╚██████╗  ██║  ╚██████╔██║  ██║  ██║\n  ╚═══╝ ╚═╝╚═════╝  ╚═╝   ╚═════╝╚═╝  ╚═╝  ╚═╝\n");
}

void defeatASCII() // Print "DEFEAT" ASCII art
{
    printf("██████╗█████████████████████╗█████╗████████╗\n██╔══████╔════██╔════██╔════██╔══██╚══██╔══╝\n██║  ███████╗ █████╗ █████╗ ███████║  ██║\n██║  ████╔══╝ ██╔══╝ ██╔══╝ ██╔══██║  ██║\n██████╔█████████║    █████████║  ██║  ██║\n╚═════╝╚══════╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝\n");
}

void tieASCII() // Print "TIE" ASCII art
{
    printf("█████████████████╗\n╚══██╔══████╔════╝\n   ██║  ███████╗\n   ██║  ████╔══╝\n   ██║  █████████╗\n   ╚═╝  ╚═╚══════╝\n");
}

/* This function prints a message and ASCII art based on the winner.
 * If the player wins, it prints a victory message and increments the
 * player score, if the AI wins, it prints a defeat message and increments
 * the AI score, if there's a tie, it prints a tie message. */
void printWin(char winner)
{
    if(winner == player)
    {
        victoryASCII();
        printf("Alt: VICTORY\n");
        playerScore++;
    }
    else if (winner == ai)
    {
        defeatASCII();
        printf("Alt: DEFEAT\n");
        aiScore++;
    }
    else
    {
        tieASCII();
        printf("Alt: TIE\n");
    }
    printf("You %d x %d AI\n", playerScore, aiScore); // Print current score
}

void gameoverASCII() // Print "GAME OVER" ASCII art
{
    printf(" ██████╗ █████╗███╗   ██████████╗     ██████╗██╗   ███████████████╗\n██╔════╝██╔══██████╗ ██████╔════╝    ██╔═══████║   ████╔════██╔══██╗\n██║  ████████████╔████╔███████╗      ██║   ████║   ███████╗ ██████╔╝\n██║   ████╔══████║╚██╔╝████╔══╝      ██║   ██╚██╗ ██╔██╔══╝ ██╔══██╗\n╚██████╔██║  ████║ ╚═╝ █████████╗    ╚██████╔╝╚████╔╝█████████║  ██║\n ╚═════╝╚═╝  ╚═╚═╝     ╚═╚══════╝     ╚═════╝  ╚═══╝ ╚══════╚═╝  ╚═╝\n");                                                                
}

/* This function asks the player if they want to play another game. It prompts
 * the player to enter 'Y' or 'N', and continues to prompt them until they enter
 * a valid input. If the player enters 'Y' it will return true, starting another
 * game, if the player enters 'N' it prints a message and exits the program. */
bool rematch()
{
    char input;
    
    // Loop until player inputs Y or N
    do {
        printf("Play again? (Y/N): ");
        while (getchar() != '\n'); // clear input buffer
        input = getchar();
        input = toupper(input);
    } while (input != 'Y' && input != 'N');

    // If player inputs N, display game over message and exit program
    if (input == 'N')
    {
        gameoverASCII();
        printf("Alt: GAME OVER\n");
        printf("Thanks for playing! See you next time :)\n");
    }

    return input == 'Y'; // Return true if player enters Y, false otherwise
}

/* This function starts a new game. It loops through player and AI moves
 * until a winner is found or there are no more empty spaces on the board.
 * If so, it breaks out of the loop and prints the board and outcome. */
void playGame()
{
    resetBoard();

    char winner = ' '; // Initialize winner to none (empty space)

    // Keep playing until there is a winner or there are no empty spaces left
    while (winner == ' ' && checkSpaces() != 0)
    {
        printBoard();

        // Prompt player to make a move and check for winner
        playerMove();
        winner = checkWin();

        // If there is a winner or no empty spaces, break out of the loop
        if(winner != ' ' || checkSpaces() == 0)
        {
            break;
        }
        
        // Let the AI make a move and check for a winner
        aiMove();
        winner = checkWin();

        // If there is a winner or no empty spaces, break out of the loop
        if(winner != ' ' || checkSpaces() == 0)
        {
            break;
        }
    }

    // Print outcome, board and announce winner
    printBoard();
    printWin(winner);
}

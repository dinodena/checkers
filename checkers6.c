#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Update for assignment 6, 
// connects to header file 
#include "checkers.h"

// moved defined macros and function declartion in header file 

// main function
int main()
{
    // call function welcomeScreen
    welcomeScreen();
    // call function clearScreen
    clearScreen();
    // call function displayExplicitBoard
//    displayExplicitBoard();
    // call function playGame
    playGame();
    // program executed successfully
    return 0;
}

// welcomeScreen function displays the Checkers logo and rules of the game
void welcomeScreen ()
{
	printf ("\t\t CCCC  HH  HH  EEEEE   CCCC  KK  KK  EEEEE  RRRRR    SSSS   \n");
	printf ("\t\tCC     HH  HH  EE     CC     KK KK   EE     RR RR   SS      \n");
	printf ("\t\tCC     HHHHHH  EEEE   CC     KKK     EEEE   RRRR     SSSS   \n");
	printf ("\t\tCC     HH  HH  EE     CC     KK KK   EE     RR RR       SS  \n");
	printf ("\t\t CCCC  HH  HH  EEEEE   CCCC  KK  KK  EEEEE  RR  RR  SSSSS   \n");
	printf ("\n\n");//
	printf ("CHECKERS GAME RULES\n\n");
    printf("\t 1. The board includes 64 alternating dark and light squares with 8 rows and 8 columns.\n");
    printf("\t 2. Each player places their pieces on the 12 dark squares in the first 3 rows closest to them.\n");
    printf("\t 3. Each of these 3 rows should have a total of 4 checkers.\n");
    printf("\t 4. The player with the black checkers always goes first.\n");
    printf("\t 5. Players can only move 1 checker 1 diagonal space forward during a regular turn.\n");
    printf("\t 6. Checkers must stay on the dark squares.\n");
    printf("\t 7. Jump the opponent's checkers to remove them from the board.\n");
    printf("\t 8. Players alternate turns.\n");
    printf("\t 9. If a player can jump their opponent's checker, the player must jump it.\n");
    printf("\t10. A player must keep capturing their opponent's checkers until no checkers are available to jump.\n");
    printf("\t11. Players king their pieces when their checkers reach the end of their opponent's side.\n");
    printf("\t12. The king can move forward and backward diagonally on the dark squares.\n");
    printf("\t13. Once a player has captured all their opponent's checkers, they have won the game!\n");
}

// function displayExplicitBoard displays a hardcoded version of an Checkers board
void displayExplicitBoard()
{
    printf("|-----------------------------------------------------|\n");
    printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  1  |     |  W  |     |  W  |     |  W  |     |  W  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  2  |  W  |     |  W  |     |  W  |     |  W  |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  3  |     |  W  |     |  W  |     |  W  |     |  W  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  4  |     |     |     |     |     |     |     |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  5  |     |     |     |     |     |     |     |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  6  |  B  |     |  B  |     |  B  |     |  B  |     |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  7  |     |  B  |     |  B  |     |  B  |     |  B  |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  8  |  B  |     |  B  |     |  B  |     |  B  |     |\n");
    printf("|-----------------------------------------------------|\n");
 }

// function clearScreen clears the screen for display purposes
void clearScreen()
{
    printf("\n\t\t\t\tHit <ENTER> to continue!\n");

	char enter;
	scanf("%c", &enter );

	// send the clear screen command Windows
    system("cls");
    // send the clear screen command for UNIX flavor operating systems
//    system("clear");
}

// updated play game for assignment 6
void playGame(){
    // declare variable for each player as a struct
    struct Player playerB;
    struct Player playerW;

    // black (B) always goes first
    int currentPlayer = PLAYER_B;
    int loop = ZERO;

    char board[ROW][COL]; // this is really a memory location of board[0][0]

    // create struct for each player
    printf("Player B, please enter your name\n");
    scanf("%s", playerB.playerName);
    playerB.playerNum = PLAYER_B;
    playerB.playChar = 'B';
    playerB.numCheckers = TWELVE;

    printf("Player W, please enter your name\n");
    scanf("%s", playerW.playerName);
    playerW.playerNum = PLAYER_W;
    playerW.playChar = 'W';
    playerW.numCheckers = TWELVE;

    printf("%s and %s, let's play Checkers!\n", playerB.playerName, playerW.playerName);
    // initializes hte board 
    initializeBoard(board);
    
    // updated while loop for assignment 6 
    while(!gameOver(playerB, playerW)){
        
        // call function displayBoard
        displayBoard(board);

        // switch players after each move
        if(currentPlayer == PLAYER_B){
            makeMove(&playerB, board);
            currentPlayer = PLAYER_W;
        }
        else if(currentPlayer == PLAYER_W){
            makeMove(&playerW, board);
            currentPlayer = PLAYER_B;
        }

        updateCheckerCount(board, &playerB);
        displayStats(playerB);

        updateCheckerCount(board, &playerW);
        displayStats(playerW);


        // setEndGame(&playerB); // commented out for testing (it works) and for submission
    }
    // calls displayBoard
    displayBoard(board);

    // displays the winner at the end 
    displayWinner(&playerB, &playerW);
}

// intializes the board
void initializeBoard(char board[ROW][COL])
{
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
            // row and column are both even
            if(row % 2 == 0 && col % 2 == 0)
                board[row][col] = SPACE;
            // row and column are both odd
            else if(row % 2 != 0 && col % 2 != 0)
                board[row][col] = SPACE;
            // row and column are not both even or both odd
            else{
                if(row < 3){
                    board[row][col] = 'W';
                }
                else if (row > 4){
                    board[row][col] = 'B';
                }
                else{
                    board[row][col] = SPACE;
                }
            }
        }
    }
}

// displays the baord 
void displayBoard(char board[ROW][COL]){
    printf("|-----------------------------------------------------|\n");
    printf("|     |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |\n");

    for(int row = 0; row < ROW; row++){
        printf("|-----------------------------------------------------|\n");
        printf("|  %d  |", (row + 1));

        for(int col = 0; col < COL; col++){
            printf("  %c  |", board[row][col]);
        }

        printf("\n");
    }

    printf("|-----------------------------------------------------|\n");
}

void makeMove(struct Player *player, char board[ROW][COL]){

    char start[THREE];
    char end[THREE];
    int valid = FALSE;

    // loop until the player enters a valid move
    while(valid == FALSE){

        printf("%s, enter location of checker to move (e.g. B6)\n", player->playerName);
        scanf("%s", start);

        printf("%s, enter new location for the checker (e.g. C5)\n", player->playerName);
        scanf("%s", end);

        printf("%s, wants to move checker %s to square %s\n", player->playerName, start, end);

        int lengthS = (int)strlen(start);
        int lengthE = (int)strlen(end);

        if( (lengthS == TWO) && (lengthE == TWO) &&
            (isValid(start, end, board, player->playChar) == TRUE) )
        {
            valid = TRUE;
            updateBoard(start, end, board);
        }
        else
        {
            valid = FALSE;
            printf("\tInvalid move, try again\n");
        }
    }
}

// updated for assignment 6 
int isValid(char start[THREE], char end[THREE], char board[ROW][COL], char playerChar){

    int valid = FALSE;

    // check if the start square has a valid checker
    valid = hasChecker(start, board, playerChar);

    // if the start square is not the correct checker, return FALSE
    if(valid == FALSE)
        return valid;

    // check if the end square is open
    valid = isOpen(end, board);

    // if the end square is not open, return FALSE
    if(valid == FALSE)
        return valid;

    // Players can only move 1 checker 1 diagonal space forward
    valid = isDiagonal(start, end, playerChar, board);

    // if the move is not diagonal, return FALSE
    if(valid == FALSE)
        return valid;

    return valid;
}

int isOpen(char end[THREE], char board[ROW][COL])
{
    int open = FALSE;

    // get the indexes for the board row and column to check the array
    int rowInt = getMoveRow(end);
    int colInt = getMoveCol(end);

    if( (rowInt != INVALID) && (colInt != INVALID) &&
        (board[rowInt][colInt] == SPACE))
    {
        open = TRUE;
        printf("\tEnd position is open!\n");
    }
    else
        open = FALSE;

    return open;
}

int hasChecker(char start[THREE], char board[ROW][COL], char playerChar)
{
    int checker = FALSE;

    // get the indexes for the board row and column to check the array
    int rowInt = getMoveRow(start);
    int colInt = getMoveCol(start);

    // check if the start square has the correct checker
    if( (rowInt != INVALID) && (colInt != INVALID) &&
        (board[rowInt][colInt] == playerChar))
    {
        checker = TRUE;
        printf("\tThe selected checker is valid!\n");
    }
    else
    {
        checker = FALSE;
    }

    return checker;
}

int getMoveCol(char move[THREE])
{
    // initialize to an invalid value
    int colInt = INVALID;
    // use the array to get the index value for the board array row
    //              0    1    2    3    4    5    6    7
    char cols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for(int col = 0; col < COL; col++)
    {
        // convert the first character to upper case
        if(toupper(move[ZERO]) == cols[col])
            colInt = col;
    }

    return colInt;
}

int getMoveRow(char move[THREE])
{
    // initialize to an invalid value
    int rowInt = INVALID;
    // use the array to get the index value for the board array column
    //              0    1    2    3    4    5    6    7
    char rows[] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    for(int row = 0; row < ROW; row++)
    {
        // the second character in the move array is the column
        if(move[ONE] == rows[row])
            rowInt = row;
    }

    return rowInt;
}

// displays stats 
void displayStats(struct Player player){

    printf("Player name:      %s\n", player.playerName);
    printf("Player number:    %d\n", player.playerNum);
    printf("Player character: %c\n", player.playChar);
    printf("Player checkers:  %d\n\n", player.numCheckers);
}

// updated for assignment 6
int isDiagonal(char start[THREE], char end[THREE], char playerChar, char board[ROW][COL]) {
    int diagonal = FALSE;

    // start and end; rows and collums 
    int sRow = getMoveRow(start);
    int sCol = getMoveCol(start);
    int eRow = getMoveRow(end);
    int eCol = getMoveCol(end);

    if (sRow != INVALID && sCol != INVALID && eRow != INVALID && eCol != INVALID) {
        // checks the approopate move for B
        if (playerChar == 'B') {
            // logic for the if statrement 
            if ((sRow - 1) == eRow && (sCol == (eCol + 1) || sCol == (eCol - 1))) {
                diagonal = TRUE;
            } else {
                // makesure its ok to jump
                if (isJump(sRow, sCol, eRow, eCol, board, playerChar)) {
                    diagonal = TRUE;
                } else {
                    diagonal = FALSE;
                }
            }
        }
        // checks move for player W
        else if (playerChar == 'W') {
            // checks ofi the move is appropiate for white 
            if ((sRow + 1) == eRow && (sCol == (eCol + 1) || sCol == (eCol - 1))) {
                diagonal = TRUE;
            } else {
                // makes sure its ok to jump
                if (isJump(sRow, sCol, eRow, eCol, board, playerChar)) {
                    diagonal = TRUE;
                } else {
                    diagonal = FALSE;
                }
            }
        }
    }

    return diagonal;
}



// update for assignment 6 
void updateBoard(char start[THREE], char end[THREE], char board[ROW][COL])
{
    // start row and col
    int sRow = getMoveRow(start);
    int sCol = getMoveCol(start);

    // end row and col
    int eRow = getMoveRow(end);
    int eCol = getMoveCol(end);

    // read the character at the start location
    char playerChar = board[sRow][sCol];

    // checks to see if jump is approaote 
    if (abs(sRow - eRow) == 2 && abs(sCol - eCol) == 2) {
        // math for jump location 
        int jumpedRow = (sRow + eRow) / 2;
        int jumpedCol = (sCol + eCol) / 2;

        // where on the board the character will jump
        board[jumpedRow][jumpedCol] = SPACE;
    }

    // updates the spaces and place of the checkers piece 
    board[eRow][eCol] = playerChar;
    board[sRow][sCol] = SPACE;
}

// int isJump(int sRow, int sCol, int eRow, int eCol, char board[ROW][COL], char playerChar)
int isJump(int sRow, int sCol, int eRow, int eCol, char board[ROW][COL], char playerChar){
    // Checks to see the type of move 1 space or 2
    if (abs(sRow - eRow) == 2 && abs(sCol - eCol) == 2)
    {
        // location of checkers piece equation 
        int jumpedRow = (sRow + eRow) / 2;
        int jumpedCol = (sCol + eCol) / 2;

        // checks for the jump location 
        if (board[jumpedRow][jumpedCol] != SPACE && board[jumpedRow][jumpedCol] != playerChar){
            // Return if the movie 
            return TRUE;
        }
    }
    // returns for invalid move 
    return FALSE;
}

// displays the winner 
void displayWinner(struct Player* playerB, struct Player* playerW){
    // checks which player will win the game 
    if (playerB->numCheckers == 0 && playerW->numCheckers == 0){
        printf("It's a draw!\n");
    }
    else if (playerB->numCheckers == 0){
        printf("Player %s (White) wins!\n", playerW->playerName);
    }
    else if (playerW->numCheckers == 0){
        printf("Player %s (Black) wins!\n", playerB->playerName);
    }
    else{
        printf("The game is still ongoing.\n");
    }

    // Display stats for each player
    displayStats(*playerB);
    displayStats(*playerW);
}

// ends the set end game 
void setEndGame(struct Player* player){
    player->numCheckers = 0; // ends hte game 
}

// checks to see if the game is over 
int gameOver(struct Player playerB, struct Player playerW){
    // checks game over condtion 
    if (playerB.numCheckers == 0 || playerW.numCheckers == 0){
        return TRUE; // returns true if either side has 0 pieces 
    }
    return FALSE; // when the game is not true 
}



// checks the number of pieces left on the board
void updateCheckerCount(char board[ROW][COL], struct Player *player){
    int checker = 0;
    // checks the number of pieces on hte board 
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
            if(board[row][col] == player->playChar){
                checker++;
            }
        }
    }
    player->numCheckers = checker; // updates the number of checkers pieces for the player 
}

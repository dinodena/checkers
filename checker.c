//Dena Attar
//


// declared liabaries
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes 
void welcomeScreen();
void clearScreen();
void displayExplicitBoard();

// main function 
int main(){

    // calls welcome screen
    welcomeScreen();
    clearScreen(); // calls clear screen to clear the welcome screen  
    displayExplicitBoard(); // calls displayExplicitBoard so the board to be displayed on the screen 
    
    return 0; 
}
// displays the welcome screen
void welcomeScreen(){
    // displays checkers output for the welcome screen
    printf("\t\t  CCCC  HH  HH  EEEEE    CCCC  KK  KK EEEEEE  RRRRR   SSSS   \n");
    printf("\t\t CC     HH  HH  EE      CC     KK KK  EE      RR RR  SS      \n");
    printf("\t\t CC     HHHHHH  EEEE    CC     KKK    EEEEE   RRRR    SSSS   \n");
    printf("\t\t CC     HH  HH  EE      CC     KK KK  EE      RR RR      SS  \n");
    printf("\t\t  CCCC  HH  HH  EEEEE    CCCC  KK  KK EEEEEE  RR  RR  SSSSS  \n");

    // displays the rules for the checkrs game
    printf("\n\n");
    printf("CHECKERS GAME RULES\n\n");
    printf("\t 1. The board includes 64 alternating dark and light squares with 8 rows and 8 columns.\n");
    printf("\t 2. Each player places their pieces on the 12 dark squares in the first 3 rows closest to them.\n");
    printf("\t 3. The player with the black checkers always goes first.\n");
    printf("\t 4. Each of these 3 rows should have a total of 4 checkers.\n");
    printf("\t 5. Players can only move 1 checker 1 diagonal space forward during a regular turn.\n");
    printf("\t 6. Checkers must stay on the dark squares.\n");
    printf("\t 7. Jump the opponent's checkers to remove them from the board.\n");
    printf("\t 8. PLayers alternate turns.\n");
    printf("\t 9. If a player can jump their opponent's checker, the player must jump it.\n");
    printf("\t 10. A player must keep capturing their opponent's checkers until no checkers are available to jump.\n");
    printf("\t 11. Players king their pieces when their checkers reach the end of their opponent's side.\n");
    printf("\t 12. The king can move forward and backward diagonally on the dark squares.\n");
    printf("\t 13. Once a player has captured all their opponent's checkes, they have won the game!\n");

}

// clears screen (used to clear welcome screen)
void clearScreen(){
    // prompts user to press enter to begin the game
    printf("\n\t\t\t\tHit <ENTER> to continue!\n");
    char enter; // declares a variable to enter 
    // clears screen when enter is pressed 
    scanf("%c", &enter); 
    // clears screen for windows
    system("cls");
    // clears screen for UNIX flavor (MAC) operating system
    //system("clear");
}

// displays the board 
void displayExplicitBoard(){
    // displays the checkers based numbers and letters W = white B = black
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
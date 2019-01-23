/**************************************************************************************************
 ** Name: Dustin Jones
 ** Date: Nov 10, 2017
 ** Description: This is the Fantasy Combat Game for project 4. This program focuses on the development
 ** of five characters wtih special abilites that do battle. The characters include a barbarian, a
 ** vampire, a blue men, a medusa, and Harry Potter. This program will also include a basic menu
 ** that tests the battle between these characters. The battle style in tournament format.
 **************************************************************************************************/

#include <iostream> //for cout, endl
#include "Game.hpp"
#include "Barbarian.hpp"
using std::cout;
using std::cin;
using std::endl;

/* Function Prototypes */
void welcomeMessage();

/* Main Function */
int main() {
    welcomeMessage();
    
    Game game;
    game.menu();
    
    cout << "Have a nice day!" << endl;
    return 0;
}

/*
 * Function: welcomeMessage
 * Usage: welcomeMessage()
 * -------------------------
 * Prints a welcome message to the screen and explains what the program does.
 */
void welcomeMessage() {
    cout << "Welcome to the Fantasy Combat Game! This game allows the player to do tournament style "
    << "battle with fantasy characters. The player can choose between the following: Barbarian, "
    << "Vampire, Blue Men, Medusa, and the feared Harry Potter! Each character posseses a unique "
    << "special ability to allow them to conquer their opponent. Enjoy!!! \n" << endl;
}

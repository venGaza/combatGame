/*
 * Class: Game
 * -------------------------
 * This is the implementation file for the Game class. This class stores the game menu function and
 * allows the user to select two characters to battle it out. The characters will take turns attacking
 * one another until one character is defeated when their strength reaches 0. At the end of the game,
 * the user will be prompted if they want to play again. If not, the program exits.
 */

#include "Game.hpp"
#include "Queue.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream> //for cout, cin, endl
#include <iomanip>  //for setw
#include <string> //for string
#include "getInteger.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

/*
 * Function: Game::Game()
 * Usage: Game()
 * -------------------------
 * This is the default constructor for the Game class. This function sets default values for the
 * Game object.
 */
Game::Game() {
    exitProgram = false;
    round = 1;
    glare = 100;
    teamOneLineup = new Queue;
    teamTwoLineup = new Queue;
    loserLineup = new Queue;
    characterChoice = 1;
    teamOneScore = 0;
    teamTwoScore = 0;
    winner = 0;
}

/*
 * Function: Game::~Game()
 * Usage: ~Game()
 * -------------------------
 * This is the destructor for the Game class.
 */
Game::~Game() {
    teamOneLineup->~Queue();                        //Delete all queue nodes
    teamTwoLineup->~Queue();
    loserLineup->~Queue();
    
    delete teamOneLineup;                           //Delete all queues
    delete teamTwoLineup;
    delete loserLineup;
}

/*
 * Function: Game::menu()
 * Usage: gameObj.menu()
 * -------------------------
 * This is a public member function for the Game class. This function creates the menu for the class
 * and allows the user to play through the game or exit.
 */
void Game::menu() {
    while (!exitProgram) {
        cout << setw(18) << "Menu" <<endl                           //Menu Header
        << "---------------------------------" << endl;
        
        cout << "1. Play Game" << endl                              //Menu Choices
        << "2. Exit" << endl << endl
        << "Please select a number: ";
        
        int menuSelection = getInteger();
        cout << endl;
        validate(menuSelection, 1, 2);
        
        if (menuSelection == 1) {                                    //1. Play Game
            chooseLineupAndFill();                                   //Team size and character select
            
            cout << setw(18) << "Team One vs Team Two" <<endl        //Header
            << "---------------------------------" << endl;
            
            while (!teamOneLineup->isEmpty() && !teamTwoLineup->isEmpty()) {
                battle();                                            //1 on 1 battle
                endOfFight();                                        //Fight results
            }
        
            tournamentEnd();                                         //Tournament overall results
            printLoserOption();
        } else {                                                     //2. Exit
            exitProgram = true;
        }
    }
}
/****************************************************************************************************
 *                                          GETTERS                                                 *
 ***************************************************************************************************/

/****************************************************************************************************
 *                                     PRIVATE FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * Function: Game::validate(int&, int, int)
 * Usage: validate(selection, min, max)
 * -------------------------
 * This is a private member function for the Game class. This function validates the user input to
 * make sure it falls between a certain range. It takes a selection choice by reference as well as
 * a min and max value.
 */
void Game::validate(int& selection, int min, int max) {
    while(selection < min || selection > max) {
        cout << "The number you input is invalid. Please enter a new number: ";
        selection = getInteger();
        cout << endl;
    }
}

/*
 * Function: Game::chooseLineupandFill()
 * Usage: chooseLineupAndFill()
 * -------------------------
 * This is a private member function for the Game class. This function allows the user to select the
 * team sizes and select the characters for each team.
 */
void Game::chooseLineupAndFill() {
    cout << "Please choose a lineup size for team 1 (between 1 and 10): ";
    teamOneSize = getInteger();
    cout << endl;
    validate(teamOneSize, 1, 10);
    
    cout << "Please choose a lineup size for team 2 (between 1 and 10): ";
    teamTwoSize = getInteger();
    cout << endl;
    validate(teamTwoSize, 1, 10);
    
    for (int i = 1; i <= teamOneSize; i++) {
        cout << "Team One - Character " << i << endl;
        characterSelection(teamOneLineup);
    }
    
    for (int i = 1; i <= teamTwoSize; i++) {
        cout << "Team Two - Character " << i << endl;
        characterSelection(teamTwoLineup);
    }
}

/*
 * Function: Game::endOfFight()
 * Usage: endOfFight()
 * -------------------------
 * This is a private member function for the Game class. This function runs at the end of a battle
 * between two characters. The winner of the fight is moved to the end of the queue and the loser
 * is moved to the loserLineup queue. Scores are also updated: the winning team gets 2 points while
 * the losing team loses 1 point.
 */
void Game::endOfFight() {
    if (winner == 1) {
        loserLineup->addLoser(teamTwoLineup);
        teamTwoLineup->removeFront();
        if (!teamTwoLineup->isEmpty()){
            teamOneLineup->getFront()->recover();
        }
        teamOneLineup->rotate();
        teamOneScore += 2;
        teamTwoScore -= 1;
    } else {
        loserLineup->addLoser(teamOneLineup);
        teamOneLineup->removeFront();
        if (!teamOneLineup->isEmpty()){
            teamTwoLineup->getFront()->recover();
        }
        teamTwoLineup->rotate();
        teamTwoScore += 2;
        teamOneScore -= 1;
    }
}

/*
 * Function: Game::tournamentEnd()
 * Usage: tournamentEnd()
 * -------------------------
 * This is a private member function for the Game class. This function prints out the results of the
 * tournament.
 */
void Game::tournamentEnd() {
    if (teamOneLineup->isEmpty()) {
        cout << "Team one has run out of fighters!" << endl << endl;
    } else {
        cout << "Team two has run out of fighters!" << endl << endl;
    }
    
    cout << "Team One Score: " << teamOneScore << endl
    << "Team Two Score: " << teamTwoScore << endl << endl;
    if (teamOneScore > teamTwoScore) {
        cout << "Team One is the WINNER of the tournament!!!" << endl << endl;
    } else if (teamTwoScore > teamOneScore) {
        cout << "Team Two is the WINNER of the tournament!!!" << endl << endl;
    } else {
        cout << "The tournament ended in a tie. Boooooooo!!!" << endl << endl;
    }
}

/*
 * Function: Game::printLoserOption()
 * Usage: printLoserOption()
 * -------------------------
 * This is a private member function for the Game class. This function allows the user to print out
 * the names of the characters who were defeated and are located in the user queue. 
 */
void Game::printLoserOption() {
    cout << "1. Display fighters in loser pile" << endl       //Menu Choices
    << "2. Go to main menu" << endl << endl
    << "Please select a number: ";
    
    int menuSelection = getInteger();
    cout << endl;
    validate(menuSelection, 1, 2);
    
    if (menuSelection == 1) {
        loserLineup->printQueue();                          //Print out the losers queue
    }
}

/*
 * Function: Game::characterSelection()
 * Usage: Game()
 * -------------------------
 * This is a private member function for the Game class. This function allows the user to choose
 * two characters to battle each other.
 */
void Game::characterSelection(Queue* team) {
    
    cout << setw(18) << "Character Selection" <<endl         //Header
    << "---------------------------------" << endl;
    
    cout << "1. Barbarian" << endl                           //Character Choices
    << "2. Vampire" << endl
    << "3. Blue Men" << endl
    << "4. Medusa" << endl
    << "5. Harry Potter" << endl << endl
    << "Please select a character(choose corresponding number): ";
    
    characterChoice = getInteger();                            //Select character
    cout << endl;
    validate(characterChoice, 1, 5);
    
    string name = "";
    cout << "Please enter a name for the character: ";
    getline(cin, name);
    cout << endl;
    
    team->addBack(characterChoice, name);                    //Add character to team queue
}

/*
 * Function: Game::battle()
 * Usage: battle()
 * -------------------------
 * This is a private member function for the Game class. This function battles the two characters.
 */
void Game::battle() {
    string teamOneFighterName = teamOneLineup->getFront()->getName();
    string teamOneFighterType = teamOneLineup->getFront()->getType();
    string teamTwoFighterName = teamTwoLineup->getFront()->getName();
    string teamTwoFighterType = teamTwoLineup->getFront()->getType();
    
    cout << "Prepare for a grand battle between the mighty "
         << teamOneFighterName << " (" << teamOneFighterType << ") and the nefarious "
         << teamTwoFighterName << " (" << teamTwoFighterType << ")" << endl << endl;
    
    teamOneLineup->getFront()->printCharacteristic();
    teamTwoLineup->getFront()->printCharacteristic();
    pause();
    
    while (teamOneLineup->getFront()->getStrength() > 0 &&
            teamTwoLineup->getFront()->getStrength() > 0) {
        printRound();
        advanceRound();
        round++;
    }
    
    printWinner();
}

/*
 * Function: Game::printRound()
 * Usage: printRound()
 * -------------------------
 * This is a private member function for the Game class. This function prints the current round.
 */
void Game::printRound() {
    cout << setw(18) << "Round " << round << endl         //Round Header
    << "---------------------------------" << endl;
}

/*
 * Function: Game::advanceRound()
 * Usage: battle()
 * -------------------------
 * This is a private member function for the Game class. This function advances the battle by one round.
 */
void Game::advanceRound() {
    characterOneAttack();
    cout << "---------------------------------" << endl;
    characterTwoDefend();
    
    pause();
    
    if (teamTwoLineup->getFront()->getStrength() > 0) {
        cout << "---------------------------------" << endl;
        characterTwoAttack();
        cout << "---------------------------------" << endl;
        characterOneDefend();
    }
    
    pause();
}

/*
 * Function: Game::characterOneAttack()
 * Usage: characterOneAttack()
 * -------------------------
 * This is a private member function for the Game class. This function allows character one to attack
 * opponent.
 */
void Game::characterOneAttack() {
    cout << teamOneLineup->getFront()->getName() << " attacking "
    << teamTwoLineup->getFront()->getName() << "(Armor: " << teamTwoLineup->getFront()->getArmor()
    << " Strength: " << teamTwoLineup->getFront()->getStrength() << ")" << endl << endl;
    
    teamOneLineup->getFront()->attackChar();
}

/*
 * Function: Game::characterTwoAttack()
 * Usage: characterTwoAttack()
 * -------------------------
 * This is a private member function for the Game class. This function allows character two to attack
 * opponent.
 */
void Game::characterTwoAttack() {
    if (teamTwoLineup->getFront()->getStrength() > 0) {
        cout << teamTwoLineup->getFront()->getName() << " attacking "
        << teamOneLineup->getFront()->getName() << "(Armor: " << teamOneLineup->getFront()->getArmor()
        << " Strength: " << teamOneLineup->getFront()->getStrength() << ")" << endl << endl;
        
        teamTwoLineup->getFront()->attackChar();
    }
}

/*
 * Function: Game::characterOneDefend()
 * Usage: characterOneDefend()
 * -------------------------
 * This is a private member function for the Game class. This function allows character one to defend.
 */
void Game::characterOneDefend() {
    if (teamTwoLineup->getFront()->getAttackRoll() == glare){         //Check for Medusa's GLARE special
        cout << teamOneLineup->getFront()->getName() << " has turned to stone." << endl << endl;
        teamOneLineup->getFront()->setStrength(0);
    } else {
        teamOneLineup->getFront()->defenseChar(teamTwoLineup->getFront()->getAttackRoll());
    }
}

/*
 * Function: Game::characterTwoDefend()
 * Usage: characterTwoDefend()
 * -------------------------
 * This is a private member function for the Game class. This function allows character two to defend.
 */
void Game::characterTwoDefend() {
    if (teamOneLineup->getFront()->getAttackRoll() == glare){         //Check for Medusa's GLARE special
        cout << teamTwoLineup->getFront()->getName() << " has turned to stone." << endl << endl;
        teamTwoLineup->getFront()->setStrength(0);
    } else {
        teamTwoLineup->getFront()->defenseChar(teamOneLineup->getFront()->getAttackRoll());
    }
}

/*
 * Function: Game::printWinner()
 * Usage: printWinner()
 * -------------------------
 * This is a private member function for the Game class. This function prints the winner of the game.
 */
void Game::printWinner() {
    if (teamTwoLineup->getFront()->getStrength() <= 0) {
        cout << teamOneLineup->getFront()->getName() << " (TEAM ONE) is the WINNER after "
             << round << " rounds!" << endl << endl;
        winner = 1;
    } else {
        cout << teamTwoLineup->getFront()->getName() << " (TEAM TWO) is the WINNER after "
             << round << " rounds!" <<  endl << endl;
        winner = 2;
    }
    
    round = 0;                                  //Reset round counter for next game
}

/*
 * Function: pause
 * Usage: pause()
 * -------------------------
 * This is a member function for the Zoo class. This function pauses the program.
 */
void Game::pause() {
    cout << "Press enter to continue" << endl;
    char ch  = cin.get();   //PAUSE
    while (ch != '\n') {
        cin.clear();
        ch = cin.get();
    }
}

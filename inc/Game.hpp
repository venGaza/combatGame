/*
 * Class: Game
 * -------------------------
 * This is the interface file for the Game class. This class stores the game menu function and allows
 * the user to select two characters to battle it out. The characters will take turns attacking one
 * another until one character is defeated when their strength reaches 0. At the end of the game, the
 * user will be prompted if they want to play again. If not, the program exits.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include "Queue.hpp"

class Game {
public:
    Game();                                     //Constructor
    ~Game();                                    //Destructor
    void menu();                                //Game Menu
    
private:
    //Functions
    void validate(int&, int, int);              //Validates input is in range
    void chooseLineupAndFill();                 //Sets up team size and fills with characters
    void endOfFight();                          //Prints out results of fight
    void tournamentEnd();                       //Prints out the final results of tournament
    void printLoserOption();                    //Allows user to print out the loser names in order
    void characterSelection(Queue*);            //User selects characters
    void battle();                              //Starts the character battle
    void printRound();                          //Prints out current round
    void advanceRound();                        //Advances current round
    void characterOneAttack();                  //Character one attacks character two
    void characterTwoAttack();                  //Character two attacks character one
    void characterOneDefend();                  //Character one defends an attack
    void characterTwoDefend();                  //Character two defends an attack
    void printWinner();                         //Prints out winner of battle
    void pause();                               //Pauses game
    
    //Variables
    bool exitProgram;
    int round;
    int glare;
    
    //Tournament Variables
    int teamOneSize;
    int teamTwoSize;
    Queue* teamOneLineup;
    Queue* teamTwoLineup;
    Queue* loserLineup;
    int characterChoice;
    int teamOneScore;
    int teamTwoScore;
    int winner;
};

#endif

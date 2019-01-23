/*
 * Class: BlueMen
 * -------------------------
 * This is the interface file for the BlueMen class. This subclass of Character stores the
 * characteristics and special abilities of the BlueMen class.
 */

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character {
public:
    BlueMen();                          //Default Constructor
    virtual void attackChar();          //Attack Function
    virtual void defenseChar(int);      //Defense Function
    virtual void printCharacteristic(); //Print characteristics
    
    
protected:
private:
    //Functions
    void printDefenseResult(int);          //Prints defense result
    
    //Variables
    int defense;
    int damage;
};
#endif

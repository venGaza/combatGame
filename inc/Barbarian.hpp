/*
 * Class: Barbarian
 * -------------------------
 * This is the interface file for the Barbarian class. This subclass of Character stores the
 * characteristics and special abilities of the Barbarian class.
 */

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
public:
    Barbarian();                        //Default Constructor
    virtual void attackChar();          //Attack Function
    virtual void defenseChar(int);      //Defense Function
    virtual void printCharacteristic(); //Print characteristics
    
protected:
private:
};
#endif

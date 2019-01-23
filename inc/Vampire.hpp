/*
 * Class: Vampire
 * -------------------------
 * This is the interface file for the Vampire class. This subclass of Character stores the
 * characteristics and special abilities of the Vampire class.
 */

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
public:
    Vampire();                          //Default Constructor
    virtual void attackChar();          //Attack Function
    virtual void defenseChar(int);      //Defense Function
    virtual void printCharacteristic(); //Print characteristics
    
protected:
private:
};
#endif

/*
 * Class: HarryPotter
 * -------------------------
 * This is the interface file for the HarryPotter class. This subclass of Character stores the
 * characteristics and special abilities of the HarryPotter class.
 */

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
public:
    HarryPotter();                      //Default Constructor
    virtual void attackChar();          //Attack Function
    virtual void defenseChar(int);      //Defense Function
    virtual void printCharacteristic(); //Print characteristics
    
protected:
private:
    bool hogwarts;
};
#endif

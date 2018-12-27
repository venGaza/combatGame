/*
 * Class: Medusa
 * -------------------------
 * This is the interface file for the Medusa class. This subclass of Character stores the
 * characteristics and special abilities of the Medusa class.
 */

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
public:
    Medusa();                           //Default Constructor
    virtual void attackChar();          //Attack Function
    virtual void defenseChar(int);      //Defense Function
    virtual void printCharacteristic(); //Print characteristics

protected:
private:
};
#endif

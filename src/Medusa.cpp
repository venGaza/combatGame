/*
 * Class: Medusa
 * -------------------------
 * This is the implementation file for the Medusa class. This subclass of Character stores the
 * characteristics and special abilities of the Medusa class.
 */

#include "Medusa.hpp"
#include "randomNumber.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: Medusa::Medusa()
 * Usage: Medusa()
 * -------------------------
 * This is the default constructor for the Medusa class. This function sets default values for the
 * Medusa object.
 */
Medusa::Medusa() : Character()  {
    Character::name = "Medusa";
    Character::type = "Medusa";
    Character::attack = 1;              //2d6
    Character::defense = 3;             //1d6
    Character::armor = 3;
    Character::strength = 8;
    Character::maxStrength = 8;
}

/*
 * Function: Medusa::attackChar()
 * Usage: obj.attackChar()
 * -------------------------
 * This is a public member function for the Barbarian class. This function calculates and returns an
 * attack number for the Barbarian object.
 */
void Medusa::attackChar() {
    int die1 = randomNumber(1, 6);                  //Medusa rolls 2x 6 sided die for attack
    int die2 = randomNumber(1, 6);
    int attack = die1 + die2;
    
    if (attack == 12) {                             //Simulate Medusa's glare ability
        cout << "Medusa's special ability, GLARE, has activated and turned the target to stone!"
             << endl << endl;
        attack = 100;                               //Knock out opponent
    } else {
        cout << Character::getName() << " attacks with a dice roll of: " << die1 << " " << die2
        << " for a total attack of " <<  attack << "!" << endl << endl;
        Character::setAttackRoll(attack);
    }
}

/*
 * Function: Barbarian::defenseChar()
 * Usage: obj.defenseChar()
 * -------------------------
 * This is a public member function for the Barbarian class. This function takes an attack number and
 * returns how much damage was done.
 */
void Medusa::defenseChar(int attack) {              //Medusa rolls 1x 6 sided die for defense
    int die1 = randomNumber(1, 6);
    int defense = die1;
    
    cout << Character::getName() << " defends with a dice roll of: " << die1 << " "
         <<  " for a total defense of " << defense <<  "!" << endl << endl;
    
    int damage = attack - defense - Character::getArmor();          //Calculate total damage
    
    if (damage <= 0) {
        cout << attack << "(attack) - " << defense << "(defense) - " << Character::getArmor()
        << "(armor) = " << damage << " damage taken" << endl << endl;
        
        cout << Character::getName() << " takes no damage and still has " << Character::getStrength()
        << " strength."
        << endl << endl;
    } else {
        cout << attack << "(attack) - " << defense << "(defense) - " << Character::getArmor()
        << "(armor) = " << damage << " damage taken" << endl << endl;
        
        Character::setStrength(Character::getStrength() - damage);
        if (Character::getStrength() > 0) {
            cout << Character::getName() << " now has " << Character::getStrength()
            << " strength." << endl << endl;
        } else {
            cout << Character::getName() << "'s strength is DEPLETED!" << endl << endl;
        }
    }
}

/*
 * Function: Medusa::printCharactersitic()
 * Usage: obj.printCharacteristic()
 * -------------------------
 * This is a public member function for the Medusa class. This function prints out the Medusa
 * characteristics.
 */
void Medusa::printCharacteristic() {
    cout << "Medusa: Scrawny lady with snakes for hair which helps her during combat. Just "
         << "don’t look at her!" << endl << endl;
}

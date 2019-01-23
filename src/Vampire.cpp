/*
 * Class: Vampire
 * -------------------------
 * This is the implementation file for the Vampire class. This subclass of Character stores the
 * characteristics and special abilities of the Vampire class.
 */

#include "Vampire.hpp"
#include "randomNumber.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: Vampire::Vampire()
 * Usage: Vampire()
 * -------------------------
 * This is the default constructor for the Vampire class. This function sets default values for the
 * Vampire object.
 */
Vampire::Vampire() : Character()  {
    Character::name = "Vampire";
    Character::type = "Vampire";
    Character::attack = 0;              //1d12
    Character::defense = 3;             //1d6
    Character::armor = 1;
    Character::strength = 18;
    Character::maxStrength = 18;
}

/*
 * Function: Vampire::attackChar()
 * Usage: obj.attackChar()
 * -------------------------
 * This is a public member function for the Vampire class. This function calculates and returns an
 * attack number for the Vampire object.
 */
void Vampire::attackChar() {
    int die1 = randomNumber(1, 12);                  //Vampire rolls 2x 6 sided die for attack
    int attack = die1;
    
    cout << Character::getName() << " attacks with a dice roll of: " << die1
         << " for a total attack of " <<  attack << "!" << endl << endl;
    Character::setAttackRoll(attack);
}

/*
 * Function: Vampire::defenseChar()
 * Usage: obj.defenseChar()
 * -------------------------
 * This is a public member function for the Vampire class. This function takes an attack number and
 * returns how much damage was done.
 */
void Vampire::defenseChar(int attack) {                 //Special ability charm at 50% chance
    int charm = randomNumber(1, 2);
    if (charm == 1) {
        cout << Character::getName() << "'s special ability, CHARM, has activated and "
             << "the attack has been stopped this round!" << endl << endl;
    } else {
        int die1 = randomNumber(1, 6);                  //Vampire rolls 1x 6 sided die for defense
        int defense = die1;
        
        cout << Character::getName() << " defends with a dice roll of: " << die1 << " "
        <<  " for a total defense of " << defense <<  "!" << endl << endl;
        
        int damage = attack - defense - Character::getArmor();
        
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
}

/*
 * Function: Vampire::printCharactersitic()
 * Usage: obj.printCharacteristic()
 * -------------------------
 * This is a public member function for the Vampire class. This function prints out the Vampire
 * characteristics.
 */
void Vampire::printCharacteristic() {
    cout << "Vampire: Suave, debonair, but vicious and surprisingly risilient. " << endl << endl;
}

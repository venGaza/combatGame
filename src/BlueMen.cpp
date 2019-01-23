/*
 * Class: BlueMen
 * -------------------------
 * This is the implementation file for the BlueMen class. This subclass of Character stores the
 * characteristics and special abilities of the BlueMen class.
 */

#include "BlueMen.hpp"
#include "randomNumber.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: Barbarian::Barbarian()
 * Usage: Barbarian()
 * -------------------------
 * This is the default constructor for the Barbarian class. This function sets default values for the
 * Barbarian object.
 */
BlueMen::BlueMen() : Character()  {
    Character::name = "Blue Men";
    Character::type = "Blue Men";
    Character::attack = 2;              //2d10
    Character::defense = 5;             //3d6
    Character::armor = 3;
    Character::strength = 12;
    Character::maxStrength = 12;
}

/*
 * Function: BlueMen::attackChar()
 * Usage: obj.attackChar()
 * -------------------------
 * This is a public member function for the BlueMen class. This function calculates and returns an
 * attack number for the BlueMen object.
 */
void BlueMen::attackChar() {
        int die1 = randomNumber(1, 10);                  //Blue Men rolls 2x 10 sided die for attack
        int die2 = randomNumber(1, 10);
        int attack = die1 + die2;
        
        cout << "Blue Men attacks with a dice roll of: " << die1 << " " << die2
        << " for a total attack of " << attack <<  "!" << endl << endl;
        Character::setAttackRoll(attack);
}

/*
 * Function: BlueMen::defenseChar()
 * Usage: obj.defenseChar()
 * -------------------------
 * This is a public member function for the BlueMen class. This function takes an attack number and
 * returns how much damage was done.
 */
void BlueMen::defenseChar(int attack) {
    if (Character::getStrength() > 8) {                 //Mob Level 3 Defense (3 die)
        int die1 = randomNumber(1, 6);
        int die2 = randomNumber(1, 6);
        int die3 = randomNumber(1, 6);
        defense = die1 + die2 + die3;
        
        cout << Character::getName() << "(Mob Level: 3)" << " defends with a dice roll of: "
             << die1 << " " << die2 << " " << die3 <<  " for a total defense of " << defense
             <<  "!" << endl << endl;
        
        printDefenseResult(attack);
    } else if (Character::getStrength() < 4) {          //Mob Level 2 Defense (2 die)
        Character::setDefense(4);
        
        int die1 = randomNumber(1, 6);
        int die2 = randomNumber(1, 6);
        defense = die1 + die2;
        
        cout << Character::getName() << "(Mob Level: 2) " << " defends with a dice roll of: "
             << die1 << " " << die2 <<  " for a total defense of " << defense <<  "!"
             << endl << endl;
        
        printDefenseResult(attack);
    } else {                                            //Mob Level 1 Defense (1 die)
        Character::setDefense(3);
        
        int die1 = randomNumber(1, 6);
        defense = die1;
        
        cout << Character::getName() << "(Mob Level: 1) " << " defends with a dice roll of: "
             << die1 << " for a total defense of " << defense <<  "!" << endl << endl;
        
        printDefenseResult(attack);
    }
}

/*
 * Function: BlueMen::printDefenseResult()
 * Usage: obj.printDefenseResult()
 * -------------------------
 * This is a public member function for the BlueMen class. This function prints out the results
 * of the Blue Men defense.
 */
void BlueMen::printDefenseResult(int attack) {
    damage = attack - defense - Character::getArmor();
    
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
 * Function: BlueMen::printCharactersitic()
 * Usage: obj.printCharacteristic()
 * -------------------------
 * This is a public member function for the BlueMen class. This function prints out the BlueMen
 * characteristics.
 */
void BlueMen::printCharacteristic() {
    cout << "Blue Men: They are small, 6 inch tall, but fast and tough. They are hard to hit so "
         << "they can take some damage. They can also do a LOT of damage when they crawl inside "
         << "enemies’ armor or clothing, but they lose the ability to defend themselves after "
         << "taking damage (lose mob levels). " << endl << endl;
}

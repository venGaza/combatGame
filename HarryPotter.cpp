/*
 * Class: HarryPotter
 * -------------------------
 * This is the implementation file for the HarryPotter class. This subclass of Character stores the
 * characteristics and special abilities of the HarryPotter class.
 */

#include "HarryPotter.hpp"
#include "randomNumber.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: HarryPotter::HarryPotter()
 * Usage: Medusa()
 * -------------------------
 * This is the default constructor for the HarryPotter class. This function sets default values for the
 * HarryPotter object.
 */
HarryPotter::HarryPotter() : Character()  {
    Character::name = "Harry Potter";
    Character::type = "Harry Potter";
    Character::attack = 1;              //2d6
    Character::defense = 4;             //2d6
    Character::armor = 0;
    Character::strength = 10;
    Character::maxStrength = 10;
    hogwarts = false;
}

/*
 * Function: HarryPotter::attackChar()
 * Usage: obj.attackChar()
 * -------------------------
 * This is a public member function for the HarryPotter class. This function calculates and returns an
 * attack number for the HarryPotter object.
 */
void HarryPotter::attackChar() {
    int die1 = randomNumber(1, 6);                  //HarryPotter rolls 2x 6 sided die for attack
    int die2 = randomNumber(1, 6);
    int attack = die1 + die2;
    
    cout << Character::getName() << " attacks with a dice roll of: " << die1 << " " << die2
    << " for a total attack of " <<  attack << "!" << endl << endl;
    Character::setAttackRoll(attack);
}

/*
 * Function: HarryPotter::defenseChar()
 * Usage: obj.defenseChar()
 * -------------------------
 * This is a public member function for the HarryPotter class. This function takes an attack number and
 * returns how much damage was done.
 */
void HarryPotter::defenseChar(int attack) {
    int die1 = randomNumber(1, 6);                  //HarryPotter rolls 2x 6 sided die for defense
    int die2 = randomNumber(1, 6);
    int defense = die1 + die2;
    
    cout << Character::getName() << " defends with a dice roll of: " << die1 << " " << die2
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
        } else if (Character::getStrength() <= 0 && !hogwarts) {   //Special Ability activates at 0
            cout << Character::getName() << "'s strength is DEPLETED! However, his special ability, "
                 << "HOGWARTS, has revived him!" << endl << endl;
            hogwarts = true;                                        //Hogwarts can only be used once
            Character::setStrength(20);                             //Reset Harry Potter health
        } else {
            cout << Character::getName() << "'s strength is DEPLETED!" << endl << endl;
        }
    }
}

/*
 * Function: HarryPotter::printCharactersitic()
 * Usage: obj.printCharacteristic()
 * -------------------------
 * This is a public member function for the HarryPotter class. This function prints out the HarryPotter
 * characteristics.
 */
void HarryPotter::printCharacteristic() {
    cout << "Harry Potter: He is a powerful wizard who can revive himself!" << endl << endl;
}

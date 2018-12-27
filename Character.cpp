/*
 * Class: Character
 * -------------------------
 * This is the interface file for the Character class. This class stores the character attributes for
 * each of the character types. This class also serves as the superclass for all the character types.
 */

#include "Character.hpp"
#include "randomNumber.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;


/*
 * Function: Character::Character()
 * Usage: Character()
 * -------------------------
 * This is the default constructor for the Character class. This function sets default values for the
 * Character object.
 */
Character::Character() {
    name = "Barbarian";
    type = "Barbarian";
    attack = 0;
    defense = 0;
    armor = 0;
    strength = 0;
    maxStrength = 0;
    attackRoll = 0;
}

/*
 * Function: Character::Character(char, int, int, int, int)
 * Usage: Character(char, int, int, int, int)
 * -------------------------
 * This is the overloaded constructor for the Character class. This function takes 5 parameters to
 * set the traits of the character object.
 */
Character::Character(string name, string type, int attack, int defense, int armor, int strength) {
    this->name = name;
    this->type = type;
    this->attack = attack;
    this->defense = defense;
    this->armor = armor;
    this->strength = strength;
}

/*
 * Function: Character::~Character()
 * Usage: ~Character()
 * -------------------------
 * This is the destructor for the Character class.
 */
Character::~Character() {}

/*
 * Function: void Character::recover()
 * Usage: obj.recover()
 * -------------------------
 * This is public member function of the Character class. This function rolls a random number between
 * 1 and 6 and restores a portion of health based on the number that is rolled. 
 */
void Character::recover() {
    int number = randomNumber(1, 6);
    
    if (number > 3) {
        strength = maxStrength;
        cout << name << " has recovered all health!" << endl;
        cout << "---------------------------------" << endl;
    } else {
        strength += (maxStrength - strength) * 0.5;
        cout << name << " has recovered half of lost health." << endl;
        cout << "---------------------------------" << endl;
    }
}

/****************************************************************************************************
 *                                          GETTERS                                                 *
 ***************************************************************************************************/
/*
 * Function: string Character::getName()
 * Usage: obj.getName()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object name.
 */
string Character::getName() {
    return name;
}

/*
 * Function: char Character::getType()
 * Usage: obj.getType()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object type.
 */
string Character::getType() {
    return type;
}

/*
 * Function: int Character::getAttack()
 * Usage: obj.getAttack()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object attack
 * type int: 0 = 1d12 , 1 = 2d6 , 2 = 2d10 (eg 2x 10 sided die).
 */
int Character::getAttack() {
    return attack;
}

/*
 * Function: int Character::getDefense()
 * Usage: obj.getDefense()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object attack
 * type int: 0 = 1d6 , 1 = 2d6 , 2 = 3d6 (eg 3x 6 sided die).
 */
int Character::getDefense() {
    return defense;
}

/*
 * Function: int Character::getArmor()
 * Usage: obj.getArmor()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object armor
 * number.
 */
int Character::getArmor() {
    return armor;
}

/*
 * Function: int Character::getStrength()
 * Usage: obj.getStrength()
 * -------------------------
 * This is a public member function of the Character class. This function returns the object strength
 * number.
 */
int Character::getStrength() {
    return strength;
}

int Character::getAttackRoll() {
    return attackRoll;
}

int Character::getDefenseRoll() {
    return defenseRoll;
}

/****************************************************************************************************
 *                                          SETTERS                                                 *
 ***************************************************************************************************/
/*
 * Function: void Character::setName()
 * Usage: obj.setName("string")
 * -------------------------
 * This is a public member function of the Character class. This function sets the object name.
 */
void Character::setName(string name) {
    this->name = name;
}

/*
 * Function: void Character::setType()
 * Usage: obj.setType('char')
 * -------------------------
 * This is a public member function of the Character class. This function sets the object type.
 */
void Character::setType(string type) {
    this->type = type;
}

/*
 * Function: void Character::setAttack(int attack)
 * Usage: obj.setAttack(int)
 * -------------------------
 * This is a public member function of the Character class. This function sets the object attack.
 */
void Character::setAttack(int attack) {
    this->attack = attack;
}

/*
 * Function: void Character::setDefense(int defense)
 * Usage: obj.setDefense(int)
 * -------------------------
 * This is a public member function of the Character class. This function sets the object defense.
 */
void Character::setDefense(int defense) {
    this->defense = defense;
}

/*
 * Function: void Character::setArmor(int armor)
 * Usage: obj.setArmor(int)
 * -------------------------
 * This is a public member function of the Character class. This function sets the object armor.
 */
void Character::setArmor(int armor) {
    this->armor = armor;
}

/*
 * Function: void Character::setStrength(int strength)
 * Usage: obj.setStrength(int)
 * -------------------------
 * This is a public member function of the Character class. This function sets the object strength.
 */
void Character::setStrength(int strength) {
    this->strength = strength;
}

void Character::setAttackRoll(int attackRoll) {
    this->attackRoll = attackRoll;
}

void Character::setDefenseRoll(int defenseRoll) {
    this->defenseRoll = defenseRoll;
}

/****************************************************************************************************
 *                                          GENERAL                                                 *
 ***************************************************************************************************/


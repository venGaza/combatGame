/*
 * Class: Character
 * -------------------------
 * This is the interface file for the Character class. This class stores the character attributes for
 * each of the character types. This class also serves as the superclass for all the character types.
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character {
public:
    Character();                                    //Default Constructor
    Character(string, string, int, int, int, int);  //Overloaded Constructor
    virtual ~Character();                           //Destructor
    
    //Functions
    void recover();                                 //Winner recovers portion of lost health
    
    //Getters
    string getName();
    string getType();
    int getAttack();
    int getDefense();
    int getArmor();
    int getStrength();
    int getAttackRoll();
    int getDefenseRoll();
    
    //Setters
    void setName(string);
    void setType(string);
    void setAttack(int);
    void setDefense(int);
    void setArmor(int);
    void setStrength(int);
    void setAttackRoll(int);
    void setDefenseRoll(int);
    
    //Pure Virtual Functions
    virtual void attackChar() = 0;           //Attack function
    virtual void defenseChar(int) = 0;       //Defense function
    virtual void printCharacteristic() = 0;  //Prints character description
    
protected:
    string name;
    string type;
    int attack;                             //0 = 1d12 , 1 = 2d6 , 2 = 2d10
    int defense;                            //3 = 1d6 , 4 = 2d6 , 5 = 3d6
    int armor;
    int strength;
    int maxStrength;
    int attackRoll;
    int defenseRoll;
    
private:
};
#endif

/*
 * Class: Queue
 * -------------------------
 * This is the interface file for the Queue class. This class holds the QueueNode struct which
 * represents each of the node objects. It also contains the necessary functions to create a queue
 * using a circular linked list.
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
using std::string;

class Queue {
private:
    struct QueueNode {                                  //This struct serves as character node object
        Character* character;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(int charChoice, string name) {
            next = nullptr;
            prev = nullptr;
            if (charChoice == 1) {
                character = new Barbarian;
                character->setName(name);
            } else if (charChoice == 2) {
                character = new Vampire;
                character->setName(name);
            } else if (charChoice == 3) {
                character = new BlueMen;
                character->setName(name);
            } else if (charChoice == 4) {
                character = new Medusa;
                character->setName(name);
            } else {
                character = new HarryPotter;
                character->setName(name);
            }
        }
    };
    QueueNode* head;
    
public:
    Queue();                                            //Default Constructor
    ~Queue();                                           //Destructor
    
    //Functions
    bool isEmpty();                                     //Checks to see if the queue is empty
    void addBack(int charChoice, string name);          //Adds node to queue
    void addLoser(Queue* character);                    //Transfers node from team to loser queue
    Character* getFront();                              //Returns name of first node
    void rotate();                                      //Front player now last, 2nd is first
    void removeFront();                                 //Removes node at front of queue
    void printQueue();                                  //Prints values of each node in the queue
};
#endif

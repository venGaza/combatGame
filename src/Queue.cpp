/*
 * Class: Queue
 * -------------------------
 * This is the implementation file for the Queue class. This class holds the QueueNode struct which
 * represents each of the node objects. It also contains the necessary functions to create a queue
 * using a circular linked list.
 */

#include "Queue.hpp"
#include <iostream> //for cout, endl
using std::cout;
using std::endl;

/****************************************************************************************************
 *                                    CONSTRUCTOR / DESTRUCTOR                                      *
 ***************************************************************************************************/
/*
 * Queue::Queue()
 * -------------------------
 * This is the default constructor for the Queue class. This sets the head pointer to null.
 */
Queue::Queue() {
    head = nullptr;
}

/*
 * Queue::~Queue()
 * -------------------------
 * This is the destructor for the Queue class.
 */
Queue::~Queue() {                           //While queue is not empty, remove front until it is
    while (!Queue::isEmpty()) {
        removeFront();
    }
}

/****************************************************************************************************
 *                                      PUBLIC FUNCTIONS                                            *
 ***************************************************************************************************/
/*
 * bool Queue::isEmpty()
 * -------------------------
 * This is a public member function for the Queue class. This function checks if the queue is empty
 * and if so, returns true; otherwise, return false.
 */
bool Queue::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

/*
 * void Queue::addBack(int charChoice, name)
 * -------------------------
 * This is a public member function for the Queue class. This function takes a user-inputted integer,
 * creates a QueueNode with user-inputted integer, and appends it to the back of the list.
 */
void Queue::addBack(int charChoice, string name) {
    if (Queue::isEmpty()) {                             //Empty queue
        head = new QueueNode(charChoice, name);
    } else if (head->next == nullptr){                        //One node in queue
        QueueNode* temp = new QueueNode(charChoice, name);
        temp->next = head;                                  //Attach new node to head
        temp->prev = head;
        
        head->next = temp;                                  //Attach head to new node
        head->prev = temp;
        
        temp = nullptr;
    } else {                                            //Two or more nodes in queue
        QueueNode* temp = new QueueNode(charChoice, name);
        QueueNode* nodeptr = head->prev;
        
        nodeptr->next = temp;                               //Connect new node to former last node
        temp->prev = nodeptr;
        nodeptr = nullptr;
        
        temp->next = head;                                  //Connect new node to head
        head->prev = temp;
        temp = nullptr;
    }
}

/*
 * void Queue::addLoser(Queue* character)
 * -------------------------
 * This is a public member function for the Queue class. This function takes a character QueueNode
 * object from one of the current teams and adds them to the FRONT of the loser queue.
 */
void Queue::addLoser(Queue* loser) {
    int choice = 0;
    if (loser->head->character->getType() == "Barbarian") {             //Determine type for copy
        choice = 1;
    } else if (loser->head->character->getType() == "Vampire") {
        choice = 2;
    } else if (loser->head->character->getType() == "Blue Men") {
        choice = 3;
    } else if (loser->head->character->getType() == "Medusa") {
        choice = 4;
    } else {
        choice = 5;
    }
    
    if (Queue::isEmpty()) {                             //Empty queue
        head = new QueueNode(choice, loser->head->character->getName());
    } else if (head->next == nullptr){                        //One node in queue
        QueueNode* temp = new QueueNode(choice, loser->head->character->getName());
        temp->next = head;                                  //Attach new node to head
        temp->prev = head;
        
        head->next = temp;                                  //Attach head to new node
        head->prev = temp;
        
        head = head->next;                                  //New node placed at front
        
        temp = nullptr;
    } else {                                            //Two or more nodes in queue
        QueueNode* temp = new QueueNode(choice, loser->head->character->getName());;
        QueueNode* nodeptr = head->prev;
        
        nodeptr->next = temp;                               //Connect new node to former last node
        temp->prev = nodeptr;
        nodeptr = nullptr;
        
        temp->next = head;                                  //Connect new node to head
        head->prev = temp;
        
        head = head->prev;                                  //New node placed at front
        temp = nullptr;
    }
}

/*
 * int Queue::getFront()
 * -------------------------
 * This is a public member function for the Queue class. This function returns the character of the node
 * at the front of the queue.
 */
Character* Queue::getFront() {
    if (Queue::isEmpty()) {
        return NULL;
    } else {
        return head->character;
    }
}

/*
 * int Queue::rotate()
 * -------------------------
 * This is a public member function for the Queue class. This function simulates a dequeue and enqueue
 * of the front object by shifting the head pointer to the 2nd object.
 */
void Queue::rotate() {
    if (head->next != nullptr) {                        //More than 1 character in queue
        head = head->next;
    }
}

/*
 * void Queue::removeFront()
 * -------------------------
 * This is a public member function for the Queue class. This function removes the front QueueNode
 * of the queue and free the memory.
 */
void Queue::removeFront() {
    if (Queue::isEmpty()) {                                     //Empty
        cout << "The queue is empty." << endl << endl;
    } else if (head->next == nullptr) {                         //One node in queue
        delete head->character;
        head->character = nullptr;
        delete head;
        head = nullptr;
    } else if (head->next == head->prev){                       //Two nodes in queue
        QueueNode* nodeptr = head->next;
        
        head->next = nullptr;
        head->prev = nullptr;
        delete head->character;
        head->character = nullptr;
        delete head;                                                //Delete original head node
        
        head = nodeptr;                                             //Point head pointer to new front
        head->next = nullptr;
        head->prev = nullptr;
        nodeptr = nullptr;
    } else {                                                    //Three or more nodes in queue
        QueueNode* nodeptr = head;
        head = head->next;                                          //Move head pointer to next node
        
        head->prev = nodeptr->prev;                                 //Connect new head to last node
        
        nodeptr->next = nullptr;
        nodeptr->prev = nullptr;
        delete nodeptr->character;
        nodeptr->character = nullptr;
        delete nodeptr;                                             //Delete original head node
        
        nodeptr = head->prev;
        nodeptr->next = head;                                       //Connect last node to new head node
        nodeptr = nullptr;
    }
}

/*
 * void Queue::printQueue()
 * -------------------------
 * This is a public member function for the Queue class. This function traverses through the queue
 * from head using next pointers, and prints the values of each QueueNode in the queue.
 */
void Queue::printQueue() {
    if (Queue::isEmpty()) {                                       //Empty queue
        cout << "The queue is empty." << endl << endl;
    } else if (head->next == nullptr) {                           //One node
        cout << "The loser queue is: " << endl
             << head->character->getName() << " " << head->character->getType() << endl << endl;
    } else {                                                      //More than one node
        cout << "The loser queue is: " << endl
             << head->character->getName() << " (" << head->character->getType() << ") " << endl;
        
        QueueNode* nodeptr = head->next;
        while (nodeptr != head) {                              //Print all values after head until
            cout << nodeptr->character->getName() << " (" << nodeptr->character->getType() << ") ";
            nodeptr = nodeptr->next;
            cout << endl;
        }
        
        nodeptr = nullptr;
        cout << endl << endl;
    }
}

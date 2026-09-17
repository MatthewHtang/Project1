// Incldue header guards to avoid compiler error
#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include<string>

using namespace std;

struct QNode{   //Create a Node
    int studentId;  // Our node has studentId and student name
    string studentName;     
    QNode* next;    // Node points to the next node
};

class WaitingList{
    private:
    QNode* front;   // A pointer aim at the very first of the line
    QNode* end;    // A pointer aim at the very last of the line
    int count;      // Count how many people are in the line

    public:
    //Constructor for WaitingList
    WaitingList();
    //Destructor for WaitingList
    ~WaitingList();

    void enqueue(int studentId, string studentName);    //Adds the student to the back of the line

    // Removes the student at the front of the line
    // Their info is written into studentId and studentName
    // Returns false if the list is empty or nothing to remove
    bool dequeue(int &studentId, string &studentName);

    // Look at the front person in the line (this won't remove the person)
    bool peekFront(int &studentId, string &studentName);

    // Display all the waitinglist
    void displayAll();

    // return true if its empty
    bool isEmpty();

    // count the waiting line
    int getCount();

};
#endif

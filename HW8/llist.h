//CS311 Yoshii F23 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Katie Trinh
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

#include "elem.h"

// alias el_t : element type definition
//char el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
   void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //function checks if linked list is empty
  bool isEmpty();
    
  //function to display whole linked list or disply [ empty ]
  void displayAll();

  //function to add elements to front of linked list
  void addFront(el_t);
    
  //function to add elements to rear of linked list
  void addRear(el_t);

  //function to delete elements starting from the front
  void deleteFront(el_t&);
  
    
  //function to delete elements starting from the end
  void deleteRear(el_t&);

  //---------------------------------------


  //function to delete the Ith element
  void deleteIth(int, el_t&);  // calls moveTo

  //function to insert the Ith element
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};

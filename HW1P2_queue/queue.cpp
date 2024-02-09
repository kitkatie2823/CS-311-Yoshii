//INSTRUCTION: F23 queue.cpp
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors
// NEVER delete my comments!!!
//=========================================================
//HW#: HW1P2 queue
//Your name: Katie Trinh
//Complier:  g++
//File type: Queue implementation file  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{  // initialize data members as in the notes 
	front = 0;
	rear = -1;
	count = 0;
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{
	if (count == 0)
	{return true;}
	else
	{return false;}
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{
	if (count == MAX_SIZE-1)
	{return true;}
	else
	{return false;}

}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
	if (isFull())
	{throw Overflow();}
	else
	{rear = (rear + 1)%MAX_SIZE; el[rear] = newElem; count++;}
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
	if (isEmpty())
	{throw Overflow();}
	else
	{removedElem = el[front]; front = (front+1)%MAX_SIZE; count--;}
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
	if (isEmpty())
	{throw Underflow();}
	else
	{theElem = el[front];}
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty()) { cout << "[ empty ]" << endl;}
  else
    {
      int j = front;
      cout << "[";
      for (int i = 1; i <= count; i++) //for loop to display queue
	{ cout << el[j];
	if (i < count) //checks if i is lower than count
	{j = (j+1) % MAX_SIZE;}
      cout << "]" << endl;   
    	}
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{        el_t temp = el[front];   //  need a local variable
	if (count == 1)
	{return;}
	else
	{remove(temp);
	add(temp);}
              //  call remove and add  
}


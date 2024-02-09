//CS311 Yoshii F23 stack.cpp
//INSTRUCTION:
// Look for ** to complete the program (do control-S)
// Update the comments using the HOW TO COMMENT file, 
// When done, compile stack.cpp to make sure there are no syntax errors.
// NOTE: functions are called instead of repeating
// the same lines of code.
//  NEVER delete my comments!!!!  
//=========================================================
//HW#: HW1P1 stack
//Your name: Katie Trinh
//Complier:  g++
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; // indicate an empty stack
 }
  
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing 
}
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{ if ( top == -1){ return true;} else return false; } //checks if top is at -1, then stack is empty otherwise it has elements
    
//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{  if (top == MAX-1 ) return true; else return false; } //checks if top is at max capacity, otherwise it isn't
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if (isFull()) //checks if stack is full
	{
		throw Overflow();
	}
   else { top++; el[top] = elem; } //otherwise puts element at the top of stack
}
 
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ if (isEmpty()) //checks if stack is empty
	{
		throw Underflow();
	}
  else { elem = el[top]; top--;} //otherwise removes element from the top
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ if (isEmpty()) //checks if stack is empty
	{
		throw Underflow();
	}
   else {
	elem = el[top]; //otherwise elem gets top
	 }
} 

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//         Otherwise, diplays the elements vertically.
void stack::displayAll()
{  cout << "STACK:---------" << endl;
   if (isEmpty()) cout << "[ empty ]" << endl; //checks if stack is empty
   else for (int i = top; i >= 0; i--) //otherwise loops by starting at top of stack in order to display all elements
      { cout << el[i] << endl; }
   cout << "--------------" << endl;
}
 
 
//PURPOSE: pops all elements from the stack until 
// it is empty using a while loop
void stack::clearIt()
{
   el_t temp;  // ** local variable in order to pop
   temp = el[top];
   while (!isEmpty()) //while loop to check whole stack and pop all elements
   {pop(temp);};   // do not do top = -1, use a while loop
}
 


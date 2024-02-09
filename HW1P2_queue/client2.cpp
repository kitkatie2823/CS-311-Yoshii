//CS311 Yoshii F23 client2.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments.
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Katie Trinh
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Storing a collection of elements and displaying a queue of letters being added onto, then removed
//Algorithm: Queue Application

int main()
{ queue myQueue;
  myQueue.add("A");
  myQueue.add("B");
  myQueue.add("C"); //  place "A", "B", "C" in the queue
  while(true) //  while loop -- indefinitely while(true)
    {
      try
	{  // do the steps noted in the notes 
		string letter;
		myQueue.frontElem(letter); //returns front elem
		myQueue.remove(letter); //removes string
		cout << letter << endl; //displays string
		myQueue.add(letter + "A"); //adds A onto letter, "AA"
		myQueue.add(letter + "B"); //adds B onto letter
		myQueue.add(letter + "C"); //adds C onto letter
	}//end try
      catch (queue::Overflow)
	{cerr << "OVERFLOW ERROR in queue" << endl; exit(1);}

	catch (queue::Underflow)
	{cerr << "UNDERFLOW ERROR in queue" << endl; exit(1);}
    }// end of loop

}//end main


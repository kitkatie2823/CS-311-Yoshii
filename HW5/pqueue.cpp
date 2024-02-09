// CS311 Yoshii F23 - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** NEVER delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: **
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  //  add the job j at the rear (and update count)
  //    if impossible else display error message. 
  if (count < MAX)
  {
	Q[count] = j;
	count++; 
  }
  else
  {
	cout << "ERROR: Unable to insert job." << endl;
	return;
  }
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
 for (int i = 0; i < count; i++)
 {
	cout << Q[i] << " ";
 }

cout << endl;
} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  //  simply swap the values in these locations in Q
  int temploc = Q[loc1];
  Q[loc1] = Q[loc2];
  Q[loc2] = temploc;
  return;
}

// Purpose: to make the very last job trickle up to the right location.
// Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  //  While x is > 0   
  //    compare Q[x] with the parent value (*)
  //    and if the parent value is bigger call swap & update x 
  //    to be the parent location. Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  while (x > 0)
	{
		int parent = getParent(x);
		if(Q[x] < Q[parent])
		{
			swap (x,parent);
			x = parent;
		}
		else
		{
			break;
		}
	}
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  return (childloc - 1) / 2; //  return the parent location based on the child loc
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  //  Start X at 0 (the root)
  X = 0;
  //  While X is within the array (the used portion):
  //       Find the location of the smaller child by calling getSmallerchild.
  //       (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent value,
  //          call swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.
  while (X < count)
  {
	int smallerChild = getSmallerchild(X);
	if (smallerChild == -1)
	{
		break;
	}
	
	if (Q[smallerChild] < Q[X])
	{
		swap(X,smallerChild);
		X = smallerChild;
	}
	else
	{
		break;
	}
  }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{ int LC, RC; // locations of children
  LC = 2 * i + 1; // set LC and RC first.
  RC = 2 * i + 2;
//    return the location of the smaller child 
  if (LC >= count && RC >= count)
  {
	return -1;
  }

//    Be careful because one or both of them may be
//    beyond count-1 or just the RC is beyond count-1.
//    Check LC and RC against boundaries before you 
//    compare Q contents!!!!
//    If both are beyond count-1, you want to return a special value.
 if (RC >= count || Q[LC] < Q[RC])
 {
	return LC;
 }
 else
 {
	return RC;
 }
}
// NEVER GO TO UNUSED PART OF THE ARRAY 

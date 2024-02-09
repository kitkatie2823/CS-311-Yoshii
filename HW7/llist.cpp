//CS311 Yoshii F23 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Katie Trinh
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{
	//initializes front, rear and count to default values
	Front = NULL;
	Rear = NULL;
	Count = 0; 
}

llist::~llist()
{
	while(!isEmpty())
	{
		el_t temp; //temp is to store the deleted element
		deleteFront(temp);
	} 
}

//PURPOSE: Function checks if list is empty
//PARAMETER: No parameters taken
bool llist::isEmpty() {return (Front == NULL && Rear == NULL && Count == 0); } // be sure to check all 3 data members

//PURPOSE: Function displays either [ empty ] or full list
//PARAMETER: No parameters taken
void llist::displayAll() 
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		Node* P = Front;
		cout << "[ ";
		while (P != NULL)
		{
			cout << P->Elem << " ";
			P = P->Next;
		}
		cout << "]" << endl;
	}
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: Function adds element at the end of the list
//PARAMETER: Pass an element (NewNum) to push into end of list
void llist::addRear(el_t NewNum) 
	{
		//special case for adding a new node
		if (isEmpty())
		{
			Front = new Node;
			Rear = Front;
			Front->Elem = NewNum;
			Front->Next = NULL;
		}
		//regular case for adding a new node
		else
		{
			Rear->Next = new Node;
			Rear = Rear->Next;
			Rear->Elem = NewNum;
			Rear->Next = NULL;
		}
		Count++;
	} // comment the 2 cases

//PURPOSE: Function adds element at the front of the list
//PARAMETER: Pass an element (NewNum) to push into beginning of list
void llist::addFront(el_t NewNum) 
{
	//special case for adding a new node
	if (isEmpty())
	{
		Front = new Node;
		Rear = Front;
		Front->Elem = NewNum;
		Front->Next = NULL;
	}
	//regular case for adding a new node
	else
	{
		Node* temp = new Node;
		temp->Elem = NewNum;
		temp->Next = Front;
		Front = temp;
	}
	Count++;
} // comment the 2 cases

//PURPOSE: Function deletes an element from the beginning of the list
//PARAMETER: Provides an element (OldNum) to store the removed element
void llist::deleteFront(el_t& OldNum) 
{
	//error case
	if (isEmpty())
	{
		throw Underflow();
	}
	
	//is empty after deletion
	if (Count == 1)
	{
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
	}
	//regular case
	else 
	{
		OldNum = Front->Elem;
		Node* Second = Front->Next;
		delete Front;
		Front = Second;
	}
	Count--;
} // comment the 3 cases

//PURPOSE: Function deletes an element from the end of the list
//PARAMETER: Provides an element (OldNum) to store removed element
void llist::deleteRear(el_t& OldNum)
{
	//error case
	if (isEmpty())
	{
		throw Underflow();
	}
	
	//special case, empty after deletion
	if (Count == 1)
	{
		OldNum = Rear->Elem;
		delete Rear;
		Front = NULL;
		Rear = NULL;
	}
	//regular case
	else
	{
		OldNum = Rear->Elem;
		Node* Current = Front;
		while (Current->Next != Rear)
		{
			Current = Current->Next;
		}
		delete Rear;
		Rear = Current;
		Rear->Next = NULL;
	}
	Count--;
} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  temp = Front;

  for (int k = 0; k < J - 1; k++)
  {
	temp = temp->Next;
  }
}

//PURPOSE:Function to delete an element at the Ith index
//PARAMETER: It takes int i to find the Index and stores the deleted element into OldNum
void llist::deleteIth(int I, el_t& OldNum) 
{
	//error case
	if (I < 1 || I > Count)
	{
		throw OutOfRange();
	}
	
	//special case
	if (I == 1)
	{
		deleteFront(OldNum);
	}
	else if (I == Count)
	{
		deleteRear(OldNum);
	}
	//regular case
	else
	{
		Node* temp = Front;
		moveTo(I-1, temp);
		Node* deleteTemp = temp->Next;
		OldNum = deleteTemp->Elem;
		temp->Next = deleteTemp->Next;
		delete deleteTemp;
		Count--;
	}
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  
 
//PURPOSE:Function to insert an element at the Ith index
//PARAMETER: It takes int i to find where to insert i and takes el_t newNum to insert element at index. 
void llist::insertIth(int I, el_t newNum) 
{
	//error case
	if (I < 1 || I > Count + 1)
	{
		throw OutOfRange();
	}
	
	Node *temp = Front;
	moveTo(I-1, temp);
	
	//special case
	if (I == 1)
	{
		addFront(newNum);
		return;
	}
	//special case
	else if (I == Count + 1)
	{
		addRear(newNum);
		return;
	}
	//regular case
	else
	{
		Node *newNode = new Node;
		newNode->Elem = newNum;
		newNode->Next = temp->Next;
		temp->Next = newNode;
	}
	
	Count++;
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:Function as a copy constructor
//PARAMETER:Takes llist and copies it
llist::llist(const llist& Original) 
{
	Front = NULL;
	Rear = NULL;
	Count = 0;
	Node* p = Original.Front;
	while (p != NULL)
	{
		this->addRear(p->Elem);
		p = p->Next;
	}
} // use my code

//PURPOSE:Function to obtain the same value as another llist
//PARAMETER:Takes in a llist and copies current values
llist& llist::operator=(const llist& OtherOne) 
{
	el_t x;
	if (&OtherOne != this)
	{
		while (!this->isEmpty())
		{
			this->deleteRear(x);
		}
		Node* P = OtherOne.Front;
		while (P!= NULL)
		{
			this->addRear(P->Elem);
			P = P->Next;
		}
	}
	return *this;
} // use my code


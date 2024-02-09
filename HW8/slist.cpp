// CS311 Yoshii F23 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{}


// positions always start at 1

int slist::search(el_t key)
{
	int pos = 1;
	Node* current = Front;
	
	while (current != NULL)
	{
		if (current->Elem == key)
		{
			return pos;
		}
		current = current->Next;
		pos++;
	}
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos)
{
	if (pos < 1 || pos > Count)
	{
		throw OutOfRange();
	}
		Node* temp;
		moveTo(pos,temp);
		temp->Elem = element;
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  // if the same lengths,
  // check each node to see if the elements are the same
	if (Count != OtherOne.Count)
	{
		return false;
	}
		Node* P = Front;
		Node* Q = OtherOne.Front;

		while (P != NULL)
		{
			if (P->Elem != Q->Elem)
			{
				return false;
			}
			P = P->Next;
			Q = Q->Next;
		}
	
	return true;
}

el_t slist::search2(el_t X)
{
        el_t M; // blank
        // X has only the ID part set
        // In the slist look for matching el_t in ELem (same code as search)
        // return el_t obj or if not found
	int pos = search(X);
	if (pos != 0)
	{
		Node* current = Front;
		for (int i = 1; i < pos; i++)
		{
			current = current->Next;
		}
		M = current->Elem;
	}
        return M;
}

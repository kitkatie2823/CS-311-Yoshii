// CS311 Yoshii F23 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Katie Trinh
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
// For EC: you have to shorten the long key first!!!!
int htable::hash(int key)
{ return key  % TSIZE;  }

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.getkey());  // hash with the key part
  this->table[slot].addRear(element);  // Note that this means adding the element to a slist in the slot (call addRear)
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 el_t foundelement = this->table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return foundelement; // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int skey)
{
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
  selement.setkey(skey); //  initialize selement with just the skey
  int location = this->table[slot].search(selement); //  call slist's search which gives you the location I and then deleteIth
  //  return the slot number
  if (location != 0)
   {
	this->table[slot].deleteIth(location,selement);
   }
  return slot;
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ int akey;
  string fullname;
  int ssn;
  int pin;
  int slot;
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  while (fin >> akey){ 
    // fin other parts and create an element
    fin >> fullname;
    fin >> ssn;
    fin >> pin;
    slot = hash(akey);
    el_t newElem(akey, fullname, ssn, pin);
    int slotNum = add(newElem);
    // YOu can call the add function to add the created element to the table
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 1; i < TSIZE; i++)
    { cout << i << ":";   
      this->table[i].displayAll(); // call slist's displayAll
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  // for each non-empty slot of the table, retrieve the slist to a local variable
  // and fout each removed element.
  el_t Elem;
  for (int i = 0; i < TSIZE; i++)
  {
	while (!table[i].isEmpty())
	{
		table[i].deleteFront(Elem);
		fout << Elem << endl;
	}
  }
}

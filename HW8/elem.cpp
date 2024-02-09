// CS311 Yoshii F23 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// Edit ** parts
//  NEVER delete my comments!!
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  name = ""; // initialize other parts to be blanks
  pin = 0;
  ssn = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, int assn, int apin)
{
  key = akey;
  //  initialize other parts to be the arguments
  name = aname;
  pin = apin;
  ssn = assn;
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
  return key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(int akey)
{
  key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (this->key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (this->key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "|" << E.name << "|" << E.ssn << "|" <<  E.pin; // display other parts of E in a nice way
  return os;  
}  
// if you make it come out just like the input file, Saving to a file will
// be easier

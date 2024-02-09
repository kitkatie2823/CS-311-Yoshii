//CS311 Yoshii F23 client1.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments (Use control-S)
//The output should match my hw1stackDemo.out 
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Katie Trinh
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Stack Application Simple Math Solver
//Algorithm: Post Fix Stack

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression  

  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0') // til the end of the expression
    {
     try
       {
	 item = expression[i];  // current char
        // ** do all the steps in the algorithm given in Notes-2A
	if (item >= '0' && item <= '9') //checks if item is a number char between 0 and 9
	{ int num = item-'0'; postfixstack.push(num);}
	else if (item == '-' || item == '+' || item == '*') //checks if item is an operator, then pops into box1 and box2
	{ postfixstack.pop(box1);
	  postfixstack.pop(box2);
	  if(item == '-') //checks if item is the minus operator
	{ box1 = box2 - box1; postfixstack.push(box1);}
	else if(item == '+') //checks if item is the plus operator
	{ box1 = box2 + box1; postfixstack.push(box1);}
	else if(item == '*') //checks if item is the multiply operator
	{ box1 = box2 * box1; postfixstack.push(box1);}
	}
	else //defaults to this if item is not a number and it is not an operator the program is looking for
	{ cout << "Error. Invalid item.\n ";}
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) //catches overflow, expression is over the maximum amount allowed
	{cerr << "An Error occurred - Type is: Overflow \n"; exit(1); }
      catch (stack::Underflow) //catches underflow, expression does not have enough operands or operators or chars
	{cerr << "An Error occurred - Type is: Underflow \n"; exit(1); }
      catch (char const* errormsg ) // for invalid item case
	{cerr << "An Error occurred - Type is: " << errormsg << "\n"; exit(1); }

      // go back to the loop after incrementing i
      i++;
    };// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
   postfixstack.pop(box1);
   cout << "Answer is: " << box1 << "\n";
 // If anything is left on the stack, an incomplete expression 
 // was found so also inform the user.
   if(!postfixstack.isEmpty())
   { cerr << "Incomplete Expression. Some items were left in the stack.\n"; exit(1);}

}// end of the program

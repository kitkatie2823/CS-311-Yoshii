// CS311 Yoshii F23 hw6client.cpp
// HW6 Client file 
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Katie Trinh
// File type:  **  (tester)
// ================================================

// includes
#include <iostream>
#include "dgraph.h"
using namespace std;

 // comments
int main()
{
    //0.Declare dgraph object
    //1.fillTable()
    //2.displayGraph()
    //while (the user does not want to stop)
    //a.the user will specify which vertex     
    //b.findOutDegree of the vertex and display the result
    //b.findAdjacency of the vertex and display the result (see Hint)
    //c.catch exception to display error mesg but do not exit
    //end of while
	dgraph D;
	D.fillTable();
	D.displayGraph();
	
	char userInput;
	
	while (true)
	{
		cout << "Enter a vertex or x: ";
		cin >> userInput;
		
		if (userInput  == 'x')
		{
			break;
		}
	try
        	{
                	int outDegree = D.findOutDegree(userInput);
                	cout << "Out degree of vertex " << userInput << ": " << outDegree << endl;

                	slist l1;
                	l1 = D.findAdjacency(userInput);
                	l1.displayAll();
        	}
        catch (dgraph::BadVertex)
        	{
                	cout << "ERROR: Vertex not found." << endl;
        	}
	}
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/

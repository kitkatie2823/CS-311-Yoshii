//CS311 Yoshii F23 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Katie Trinh
// File Type: file implementation dgraph.cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
// - need a loop
 // initialize countUsed to be 0
{
	countUsed = 0;
	for (int i = 0; i < SIZE; i++)
	{
		Gtable[i].vertexName = ' ';
		Gtable[i].visit = 0;
	}
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

//Purpose: To fill a table in a nice format
//Parameter: Reads the user input file in order to fill Gtable
void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  char X;
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin(fname.c_str(), ios::in); // declare and open fname
  //while loop to fill in the table with the degree and rear into the variables
  while (fin >> Gtable[countUsed].vertexName)
	{
		fin >> Gtable[countUsed].outDegree;
		for (int i = 0; i < Gtable[countUsed].outDegree; i++)
		{
			fin >> X;
			(Gtable[countUsed].adjacentOnes).addRear(X);
		}
		countUsed++;
	}
	fin.close();
  // the rest is in HW6-help


}

//Purpose: Displays in a nice table format
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top (you have to sum it up)
	int totalEdges = 0;
	for (int i = 0; i < countUsed; i++)
	{
		totalEdges += Gtable[i].outDegree;
	}

	cout << "Total number of edges: " << totalEdges << endl;
	cout << "vertexName | totalOut | Visits | adjacentOnes" << endl;

	for (int i = 0; i < countUsed; i++)
	{
		cout << Gtable[i].vertexName << "\t\t" << Gtable[i].outDegree << "\t\t";
	cout << Gtable[i].visit << "\t\t";
	Gtable[i].adjacentOnes.displayAll();
	cout << endl;
	}
} 

//Purpose: Returns the degree of specific vertex
//Parameter: Uses Char V in order to find given vertex, may throw BadVertex
int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
	if (V < 'A' || 'A' > Gtable[countUsed - 1].vertexName)
	{
		throw BadVertex();
	}
	int index = 0;
	index = V - '0';
	index -= 17;
	return Gtable[index].outDegree;

}

//Purpose: Finds Adjacent chars
//Parameter: Uses Char V in order to return adjacent chars of a specific vertex, may throw BadVertex
slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
	
	if (V < 'A' || 'A' > Gtable[countUsed - 1].vertexName)
	{
		throw BadVertex();
	}
	
	int index = 0;
	index = V - '0';
	index -= 17;
	slist tempSList;
	tempSList = Gtable[index].adjacentOnes;
	return tempSList;
}

void dgraph::visit(int visitC, char V){

        if (V < 'A' || V > Gtable[countUsed - 1].vertexName){

                throw BadVertex();
 }
        int index = V - 'A';
        Gtable[index].visit = visitC;

}
 //Purpose: Checking if the vertex is marked or else
 // //PARAMETER: if a vertex has been marked, must return true if visited or marked otherwise return false.
  bool dgraph::isMarked(char V){
 
          if (V < 'A' || V > Gtable[countUsed - 1].vertexName){
 
                          throw BadVertex();
                              }
                                      int index = V - 'A';
                                              return Gtable[index].visit != 0;
 
 
                                              }

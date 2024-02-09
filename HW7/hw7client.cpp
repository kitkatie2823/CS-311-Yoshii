// CS311 YOSHII F23 hw7client.cpp

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Katie Trinh
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments.

dgraph G;
  stack Stack;
  slist S;
  G.fillTable();
  cout << "Before DFS" << endl;
  G.displayGraph();
  

  Stack.push('A');
  int visitcount = 0;
  char V;
  char Vv;
  while(!Stack.isEmpty()){
   Stack.pop(V);
   cout << "Removed " << V << " from the stack" << endl;

    if(!G.isMarked(V)){
      visitcount++;
      G.visit(visitcount, V);
      cout << "Visit " << V << " as " << visitcount << endl;
      S = G.findAdjacency(V);
      if(S.isEmpty()){
        cout << "Deadend reached - backup" << endl;
      }
      else{
        while(!S.isEmpty()){
          S.deleteRear(Vv);
          Stack.push(Vv);
          }
        cout << "Push adjacent verticies" << endl;
        }
    } 
    else{
    cout << V << " had already been vistied - backup" << endl;
    }    

cout << "Current Stack: " << endl;
Stack.displayAll();
}

G.displayGraph();			
}

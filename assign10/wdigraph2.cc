/*
Name:Cory Stojan
Due Date: 06Dec18
Class/Section: CSCI 340/ Sec 3
Program Number: 10
Discription: Implements graph algorithms on a weighted directional graph. Uses the Depth_first Search algorithm.
*/

// Include Statements
#include "/home/cs340/progs/18f/p10/wdigraph.h"

// Functions
//*********************************************************************************************************
/*
Function Name: depth_first(int)
Returns: Nothing
Arguments: int, u (the starting node)
Discription: traverses a digraph in the depth-first order and it prints the path it traveled
*/
void wdigraph::depth_first(int u) const{
      // local variables
      static int node = -1;
      static bool* visited = NULL;
      
      // if node value is the default (-1), set it = to u
      if (node == -1){
    node = u;

    //allocate visited array of size elements
    visited =  new bool(size);

    //set all elements of visited to false
    for(int i = 0; i < size; i++)
        visited[i] = false;
      }

      // set visited position to ture and ouptt that pos
      cout << label[u];
      visited[u] = true;

      // output the value to the matrix
      for(int i = 0; i != size; i++) {
         if (adj_matrix[u][i] != 0 && visited[i] != true){
        cout << "->";
        depth_first(i);
         }
      }

    // remove visitied node
    if (u == node){
    	cout << endl << endl;
    	node = -1;
    	delete[] visited;
    	visited = NULL;
    }
}

//*********************************************************************************************************
/*
Function Name: print_graph()
Returns: Nothing
Arguments: None
Discription: prints out the Number of nodes in the digraph and an adjaceny matrix for the digraph.
*/
void wdigraph::print_graph() const{
    // output node size and title of matrix
    cout << "\nNo of Nodes = " << get_size() << endl << endl
        << "Adjacency Matrix" << endl << endl;

    // output matrix graph.
    cout << "  |";
    for(int i = 0; i < (int) label.size(); i++)
        cout << "  " << label[i];

    cout << endl <<"--|";
    for(int i = 0; i < (int) label.size(); i++)
        cout << "---";
    cout << endl;

    for(int i = 0; i < (int) label.size(); i++){
        cout << label[i] << " |";

        for(int j = 0; j < (int) label.size(); j++){
                if(adj_matrix[i][j] != 0)
                    cout << setw(3) << adj_matrix[i][j];
            else
                    cout << setw(3) << "-";
        }
    if(i < (int) label.size() -1)
        cout << endl << "  |" << endl;
    }
    cout << endl << endl;
}

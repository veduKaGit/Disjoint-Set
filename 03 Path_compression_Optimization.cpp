// The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. 
// The find() operation traverses up from x to find root. 
// The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again. 
// If x is root of a subtree, then path (to root) from all nodes under x also compresses.


// Let the subset {0, 1, .. 9} be represented as below and find() is called for element 3.
//              9
//          /   |   \  
//         4    5    6
//        /         /  \
//       0         7    8
//      /        
//     3
//    / \         
//   1   2
// When find() is called for 3, we traverse up and find 9 as representative
// of this subset. With path compression, we also make 3 and 0 as the child of 9 so 
// that when find() is called next time for 0, 1, 2 or 3, the path to root is reduced.

//         --------9-------
//       /   /    /  \      \
//      0   4    5    6       3 
//                   /  \    /  \
//                  7    8   1   2


#include <iostream>
using namespace std;
#define n 5


int parent[n];


void initialize()
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

int find(int x)
{
    if(parent[x]==x)
        return x;
        
    return parent[x] = find(parent[x]); //just 1 line changed
    
}

void unions(int x, int y) //here we are not considering union by rank
{
    int x_rep = find(x);
    int y_rep = find(y);
    
    if(x_rep==y_rep)
    return;
    
    parent[y_rep]=x_rep;
}

int main() 
{


initialize();

unions(0,2);
unions(0,4);


cout<<find(4)<<endl;
cout<<find(3)<<endl;

return 0;
}

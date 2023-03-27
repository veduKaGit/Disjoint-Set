// Time complexity of find and union operations: 
//say we did m operations(find or union), the time complexity = O(m * log n) => same as O(log n)

// The idea is to always attach smaller depth tree under the root of the deeper tree. 
// This technique is called union by rank. 
// The term rank is preferred instead of height because if path compression technique (we have discussed it later) is used, 
// then rank is not always equal to height. Also, size (in place of height) of trees can also be used as rank. 
// Using size as rank also yields worst case time complexity as O(Logn).


#include <iostream>
using namespace std;
#define n 5


int parent[n];
int ranks[n];  //this is the additional array....here rank[i] means the height of the tree rooted with the ith element


void initialize()
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        ranks[i]=0;  //initially, rank of all the elements =0
    }
}

int find(int x)  // NO CHANGE in find function
{
    if(parent[x]==x)  
        return x;
    else
        return find(parent[x]);
    
}

void unions(int x, int y)
{
    int x_rep = find(x);   //find representative element for both of them
    int y_rep = find(y);
    
    if(x_rep==y_rep)  //if already a part of the same disjoint set
        return;
    
// The idea is to always attach smaller depth tree under the root of the deeper tree. 
    
//we first found representative, now we compare RANK OF REPRESENTATIVES!
    
    if(ranks[x_rep]<ranks[y_rep])     //FATAL ERROR => DONT compare/update rank/parent of x, y => instead do for x_rep, y_rep
        parent[x_rep] = y_rep;  
    
    else if(ranks[y_rep]<ranks[x_rep])
        parent[y_rep]=x_rep;  
    
    else  //if equal height
        {
            parent[y_rep] = x_rep;  
        
            ranks[x_rep]++; //imp.....very imp
        }
}

int main() 
{


initialize();

unions(3,4);
unions(2,3);
unions(1,2);
unions(0,1);


cout<<parent[3]<<endl;
cout<<ranks[3]<<endl;

return 0;
}

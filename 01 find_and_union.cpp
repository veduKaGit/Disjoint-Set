// Time complexity for both find and union operations: O(n)


#include <iostream>
using namespace std;
#define n 5


int parent[n];  //this array is {0,1,2,3,4}....since we initialized it
//parent[] will be used in find operation....since on every union operation, it gets updated

void initialize()  //make every element parent of itself
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
}

int find(int x)  //root of the tree will be the representative element of each disjoint set
{
    if(parent[x]==x)  //this is when that element is root of the tree
        return x;
    else
        return find(parent[x]);  //if not the root of the tree....then we move towards the root
    
}

void unions(int x, int y)
{
    int x_rep = find(x); //find representative element for both of them
    int y_rep = find(y);
    
    if(x_rep==y_rep)  //if already a part of the same disjoint set
    return;
    
    parent[y_rep]=x_rep;  //if not a part of the same disjoint set
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

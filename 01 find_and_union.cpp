#include <iostream>
using namespace std;
#define n 5


int parent[n];  //this array is {0,1,2,3,4}....since we initialized it
//paernt[] will be used in find operation....since on every union operation, it gets updated

void initialize()  //make every element parent of itself
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
    else
        return find(parent[x]);
    
}

void unions(int x, int y)
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

#include<iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g;
    g.join(0,1,5);
    g.join(0,2,7);
    g.display();

    cout<<g.isAdjacent(0,1)<<endl;


    return 0;
}
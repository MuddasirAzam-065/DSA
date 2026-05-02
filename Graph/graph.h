#include<iostream>
#include "linearqeue.h"
using namespace std;
#define MAXVER 5
struct vertex
{
    int num;
};

struct edge
{
    int adj;
    int weight;
};

class Graph
{
    private:
    struct vertex v[MAXVER];
    struct edge e[MAXVER][MAXVER] = {0};

    public:
    void join(int vertex1,int vertex2,int weight)
    {
        e[vertex1][vertex2].weight=weight;
        e[vertex2][vertex1].weight=weight;
        e[vertex1][vertex2].adj=1;
        e[vertex2][vertex1].adj=1;
    }

    void remove(int vertex1,int vertex2)
    {
        e[vertex1][vertex2].weight=0;
        e[vertex2][vertex1].weight=0;
        e[vertex1][vertex2].adj=0;
        e[vertex2][vertex1].adj=0;
    }

    bool isAdjacent(int vertex1,int vertex2)
    {
        return e[vertex1][vertex2].weight!=0;
    }

    void display()
    {
        for(int i=0;i<MAXVER;i++)
        {
            for(int j=0;j<MAXVER;j++)
            {
                cout<<e[i][j].adj<<" ";
            }
            cout<<endl;
        }
cout<<endl;
        for(int i=0;i<MAXVER;i++)
        {
            for(int j=0;j<MAXVER;j++)
            {
                cout<<e[i][j].weight<<" ";
            }
            cout<<endl;
        }
    }

    void BSF(int vertex)
    {
        bool visited[MAXVER] = {false};
        qeue<int> q(MAXVER);
        visited[vertex] = true;
        q.push(vertex);
        while (!q.isEmpty())
        {
           
        }
    }

    void DSF(int vertex)
    {
        bool visited[MAXVER] = {false};
        visited[vertex] = true;
        cout << vertex << " ";
        for (int i = 0; i < MAXVER; i++)
        {
            if (e[vertex][i].adj == 1 && !visited[i])
            {
                DSF(i);
            }
        }
    }

    void Dijkstra(int start)
    {
        int dist[MAXVER];
        bool visited[MAXVER] = {false};

        for (int i = 0; i < MAXVER; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[start] = 0;

        for (int count = 0; count < MAXVER - 1; count++)
        {
            int minDist = INT_MAX, minIndex;
            for (int v = 0; v < MAXVER; v++)
            {
                if (!visited[v] && dist[v] <= minDist)
                {
                    minDist = dist[v];
                    minIndex = v;
                }
            }

            visited[minIndex] = true;

            for (int v = 0; v < MAXVER; v++)
            {
                if (!visited[v] && e[minIndex][v].adj == 1 && dist[minIndex] != INT_MAX && dist[minIndex] + e[minIndex][v].weight < dist[v])
                {
                    dist[v] = dist[minIndex] + e[minIndex][v].weight;
                }
            }
        }

        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < MAXVER; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }
};



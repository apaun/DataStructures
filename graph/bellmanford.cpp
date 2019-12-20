//////////////////////////////////////////////////////////
// Given a graph and a source vertex src in graph, 
// find shortest paths from src to all vertices in the given graph. 
// The graph may contain negative weight edges.
/////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;

typedef pair<int, int> pii;

vector<pii> *adj;

void addEdges(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

bool bellmanfordSP(int src, int V)
{
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < V; j++)
        {
            for(auto e : adj[j])
            {
                int u = j;
                int v = e.first;
                int weight = e.second;
                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for(int j = 0; j < V; j++)
    {
        for(auto e : adj[j])
        {
            int u = j;
            int v = e.first;
            int weight = e.second;
            if (distance[v] > distance[u] + weight)
            {
                return true;
            }
        }
    }


    for(int i = 0; i < V; i++)
    {
        cout << i << " Distance : " << distance[i] << endl;
    }

    return false;
}


int main()
{
    int V = 5;

    adj = new vector<pii>[V];
    addEdges(0, 1, -1);
    addEdges(0, 2, 4);
    addEdges(1, 2, 3);
    addEdges(1, 3, 2);
    addEdges(1, 4, 2);
    addEdges(3, 2, 5);
    addEdges(3, 1, 1);
    addEdges(4, 3, -3);

    bellmanfordSP(0, V);

    return 0;
}
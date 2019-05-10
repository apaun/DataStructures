/**************************************
 * https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
 * ***********************************/

#include<iostream>
#include<vector>
#include<queue>
#include"graph.h"
using namespace std;


vector<int> *adj;

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void bfs(int u, int numberOfNodes)
{
    vector<bool> visited (numberOfNodes, false);
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(auto i : adj[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;

}

int main()
{
    int V = 4;
    adj = new vector<int>[V];

    cout << "Graph Breadth First Search" << endl;
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3);
    bfs(2, V);
    getchar();
    return 0;
}
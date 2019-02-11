/**************************************
 * https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 * https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
 * ***********************************/
#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;

vector<int> *adj;

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsUtil(vector<bool> &visited, int u)
{
    visited[u] = true;
    cout << u << " ";
    for(auto i : adj[u])
    {
        if (visited[i] == false)
            dfsUtil(visited, i);
    }
    // vector<int>::iterator i;
    // for(i = adj[u].begin(); i != adj[u].end(); ++i)
    // {
    //     if (visited[*i] == false)
    //         dfsUtil(visited, *i);
    // }
}

void dfs(int V)
{
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            dfsUtil(visited, i);
    }

    cout << endl;
}

int main()
{
    cout << "Graphs A" << endl;
    int V = 4;
    adj = new vector<int>[V];
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    dfs(V);
    getchar();
    return 0;
}
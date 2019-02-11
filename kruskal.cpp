/*****************************************
 * Minimum Spanning Tree Algorithm
 * https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
**https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
*****************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, pair<int, int>> pipii;
vector<pipii> edges, mst;
int *id;

void addEdge(int u, int v, int weight)
{
    edges.push_back(make_pair(weight, make_pair(u, v)));
}

bool compare(pipii obj1, pipii obj2)
{
    return obj1.first < obj2.first;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }

    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

void kruskal(int E)
{
    int minCost = 0;
    for(int i = 0; i < E; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;
        if (root(u) != root(v))
        {
            minCost += weight;
            union1(u, v);
            mst.push_back(edges[i]);
        }
    }
    
    // Printing Output
    for(auto e : mst)
    {
        cout << e.second.first << "---->" << e.second.second << "==" << e.first << endl; 
    }

    cout << "Minimum Spanning Tree Cost = " << minCost << endl;
}



int main()
{
    int V = 9;
    int E = 14;
    id = new int[E];
    for(int i = 0; i < E; i++)
    {
        id[i] = i;
    }
    
    
    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 

    sort(edges.begin(), edges.end(), compare);
    kruskal(E);

    return 0;
}
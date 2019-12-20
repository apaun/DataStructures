//////////////////////////////////////
// Given a graph and a source vertex in the graph, 
// find shortest paths from source to all vertices in the given graph.
///////////////////////////////////////


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;
vector<pii> *adj;

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void dijkstraSP(int src, int V)
{
    vector<int> distance(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[src] = 0;
    pq.push(make_pair(src, 0));

    while(!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();

        for(auto e : adj[u])
        {
            int v = e.first;
            int weight = e.second;
            if (distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.push(e);
            }
        }
    }

    for(int i = 0; i < V; i++)
    {
        cout << i << " Distance : " << distance[i] << endl;
    }
}

int main()
{
    // create the graph given in above fugure 
    int V = 9; 

    adj = new vector<pii>[V];
  
    //  making above shown graph 
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
  
    dijkstraSP(0, V); 
  
    return 0; 

}
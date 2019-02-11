/*****************************************
 * Minimum Spanning Tree Algorithm
 * https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
 * 
*****************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> pii;
vector<pii> *adj;

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back({u, w});
}

void primMst(int V)
{
    int s= 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> marked (V, false);
    vector<int> parent (V, -1);
    vector<int> key (V, INF);

    pq.push(make_pair(s, 0));
    key[s] = 0;
    long long cost = 0;

    while(!pq.empty())
    {
        pii q = pq.top();
        pq.pop();

        //Checking for cycle
        if(marked[q.first])
            continue;
        
        cost += q.second;
        marked[q.first] = true;

        for(auto e : adj[q.first])
        {
            int u = e.first;
            int weight = e.second;
            if(!marked[u] && key[u] > weight)
            {
                key[u] = weight;
                pq.push(e);
                parent[u] = q.first;
            }
        }
    }

    cout << "Total Cost : " << cost << endl;
    for(int i = 1; i < parent.size(); i++)
    {
        cout << parent[i] << "--->" << i << "==" << key[i] << endl;
    }
}

int main()
{

    int V = 9;
    adj = new vector<pii>[V];
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
    
    primMst(V);

    return 0;

    
}

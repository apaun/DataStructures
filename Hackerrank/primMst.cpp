#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
vector<pii> *adj;

ll primMst(int n, int start)
{
    int u = start;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n, false);
    vector<ll> parent(n, -1);
    vector<ll> key(n , LONG_LONG_MAX);

    pq.push(make_pair(u, 0));
    key[u] = 0;
    ll cost = 0;

    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        cost += top.second;
        visited[top.first] = true;

        for(auto& edge : adj[top.first])
        {
            int v = edge.first;
            int w = edge.second;
            if(key[v] > w)
            {
                key[v] = w;
                parent[v] = top.first;
                if(!visited[v])
                {
                     pq.push(edge);
                }
            }
        }
    }

    cout << cost << endl;

    cost = 0;
    for(int i = 0; i < n; i++)
    {
        cost += key[i];
    }

    return cost;
}


int main()
{
    int n, m;
    cin >> n >> m;

    adj = new vector<pii>[n];

    for(int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        if(w  > 0)
        {
            --u;
            --v;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
    }

    int start;
    cin >> start;

    cout << primMst(n, start - 1) << endl;



    return 0;
}

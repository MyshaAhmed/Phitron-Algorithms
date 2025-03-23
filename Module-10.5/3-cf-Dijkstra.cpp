// shortest path display from src to dst using djkstra algorithm:
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N=1e5+5;
vector<pair<int, int>> adj[N];
int dis[N];
int parent[N];
void dijkstra(int src)
{
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src}); // prothome distance tarpor node push
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> par=pq.top();
        pq.pop();
        int par_node=par.second;
        int par_dis=par.first;
        for (auto child : adj[par_node])
        {
            int child_node=child.first;
            int child_dis=child.second;
            if(par_dis+child_dis<dis[child_node]) // path relaxation
            {
                dis[child_node]=par_dis+child_dis;
                parent[child_node]=par_node;  // update parent array for shortest path
                pq.push({ dis[child_node],child_node});
            }
        }
    }
}
int main()
{
   
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(parent,-1,sizeof(parent));

    for(int i=1; i<=n; i++)
        dis[i] = INT_MAX;
    dijkstra(1);
    vector<int> path;
    int node=n;
    while(node!=-1)
    {
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end());
    if(dis[n]==INT_MAX)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<" ";

/* 
input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/ 
    return 0;
}
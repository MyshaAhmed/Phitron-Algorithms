#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
int parent[105];
bool vis[105];
bool cycle;

void DFS(int src)
{
    vis[src] = true;
    for(auto child:adj_list[src])
    {
        if(vis[child] && child!=parent[src])
            cycle = true;
        if(!vis[child])
        {
            parent[child] = src;
            DFS(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    // for disconnected graph:
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        DFS(i);
    }

    if(cycle)
        cout<<"cycle detected"<<endl;
    else
        cout<<"No cycle detected"<<endl;
    return 0;
}
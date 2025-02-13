#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
int parent[105];
bool vis[105];
bool cycle;

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child:adj_list[par])
        {
            if(vis[child]&& parent[par]!= child)
            {
                cycle = true;
            }
            else if(!vis[child]) // cycle found
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par; // to trace back the path
            }
        }
    }
    // if no cycle found
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
        BFS(i);
    }

    if(cycle)
        cout<<"cycle detected"<<endl;
    else
        cout<<"No cycle detected"<<endl;
    return 0;
}
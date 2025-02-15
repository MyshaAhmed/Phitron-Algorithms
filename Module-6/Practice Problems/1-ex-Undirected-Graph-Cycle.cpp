int parent[100005];
bool vis[100005];
bool cycle;

void DFS(int src,vector<vector<int>>& adj)
{
    vis[src] = true;
    for(auto child:adj[src])
    {
        if(vis[child] && child!=parent[src])
        {
            cycle = true;
            return;
        }
        if(!vis[child])
        {
            parent[child] = src;
            DFS(child,adj);
        }
    }
}

// Function to detect cycle in an undirected graph.
bool isCycle(vector<vector<int>>& adj) {
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle=false;
    // for disconnected graph:
    for(int i=0; i<adj.size(); i++)
    {
        if(!vis[i])
            DFS(i,adj);
    }

    if(cycle)
        return true;
    else
        return false;
}
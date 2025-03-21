class Solution {
    public:
    
      int parent[100005];
      bool vis[100005];
      bool cycle;
      
      void DFS(int src,vector<vector<int>>& adj)
      {
          vis[src]=true;
          for(auto child: adj[src])
          {
              if(vis[child] && parent[src]!=child)
                  cycle=true;
              if(!vis[child] )
              {
                  parent[child]=src;
                  DFS(child,adj);
              }
          }
      }
      
      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {
          int n=adj.size();
          memset(vis, false, sizeof(vis));
          memset(parent, -1, sizeof(parent));
          cycle=false;
          for(int i=0;i<n;i++)
          {
              if(!vis[i])
                  DFS(i,adj);
          }
          if(cycle)
              return true;
          else
              return false;
      }
  };
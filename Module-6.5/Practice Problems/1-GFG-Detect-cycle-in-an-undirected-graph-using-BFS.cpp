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
      void BFS(int src,vector<vector<int>>& adj)
      {
          queue<int>q;
          q.push(src);
          vis[src]=true;
          while(!q.empty())
          {
              int par=q.front();
              q.pop();
              
              for(auto child: adj[par])
              {
                  if(vis[child] && parent[par]!=child)
                      cycle=true;
                  else if(!vis[child])
                  {
                      q.push(child);
                      vis[child]=true;
                      parent[child]=par;
                  }
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
                  BFS(i,adj);
          }
          if(cycle)
              return true;
          else
              return false;
      }
  };
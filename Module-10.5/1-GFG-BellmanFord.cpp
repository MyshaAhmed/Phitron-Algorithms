class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          int max_dis=1e8;
          int n=V;
          vector<int> dis(n);
          for(int i=0;i<n;i++)
              dis[i]=max_dis;
          
          dis[src]=0;
          bool cycle=false;
          for(int i=0;i<n-1;i++)
          {
              for(auto child: edges)
              {
                  int a=child[0];
                  int b=child[1];
                  int c=child[2];
                  if(dis[a]!=max_dis && dis[a]+c<dis[b])
                  {
                      dis[b]=dis[a]+c;
                  }
              }
          }
          for(auto child: edges)
          {
              int a=child[0];
              int b=child[1];
              int c=child[2];
              if(dis[a]!=max_dis && dis[a]+c<dis[b])
              {
                  cycle=true;
                  break;
              }
          }
          if(cycle)
              return {-1};
          else 
              return dis;
      }
  };
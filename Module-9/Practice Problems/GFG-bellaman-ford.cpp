class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      
      vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
          vector<int> dis(505);
          for (int i = 0; i < v; i++)
          {
              dis[i] = 1e8;
          }
          dis[src]=0;
          for(int i = 0; i < v-1; i++) // [n-1 times bellman ford chalabo]
          {
              for(auto ed: edges)
              {
                  int a, b, c;
                  a = ed[0];
                  b = ed[1];
                  c = ed[2];
                  if(dis[a]!=1e8 && dis[a]+c<dis[b])
                  {
                      dis[b] = dis[a]+c;
                  }
              }
          }
          bool cycle = false;
          for(auto ed: edges) // extra 1 iteration for cycle detection
          {
              int a, b, c;
              a = ed[0];
              b = ed[1];
              c = ed[2];
              if(dis[a]!=1e8 && dis[a]+c<dis[b])
              {
                  cycle = true;
                  break;
              }
          }
          if(cycle)
              return {-1};
          else
          {
              return dis;
          }
  
      }
  };
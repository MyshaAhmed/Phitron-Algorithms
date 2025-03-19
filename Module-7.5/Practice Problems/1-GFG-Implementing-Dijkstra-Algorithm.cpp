class Solution {
    public:
    
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          int n=adj.size();
          vector<int> dis(n);
          for (int i = 0; i < adj.size(); i++)
              dis[i] =INT_MAX;
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
                      pq.push({ dis[child_node],child_node});
                  }
              }
          }
          
          return dis;
          
      }
  };
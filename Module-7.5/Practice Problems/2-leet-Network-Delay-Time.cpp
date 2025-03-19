class Solution {
    public:
        int dis[1005];
        vector<pair<int, int>> adj_list[1005];
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
                for (auto child : adj_list[par_node])
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
        }
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           
            for (int i = 1; i <=n; i++)
                dis[i] =INT_MAX;
    
            for(auto v: times)
            {
                adj_list[v[0]].push_back({v[1], v[2]}); // for directed weighted graph
            }
        
            // print check adj_list:
            // for (int i = 1; i <= n; i++)
            // {
            //     cout << i << " -> ";
            //     for (auto it : adj_list[i])
            //         cout << "(" << it.first << ", " << it.second << ") ";
            //     cout << endl;
            // }
            dijkstra(k);
    
            int max_delay = 0;
            for (int i = 1; i <= n; i++) {
                if (dis[i] == INT_MAX) { // If any node is unreachable
                    return -1;
                }
                max_delay = max(max_delay, dis[i]);
            }
    
            return max_delay;
        }
    };
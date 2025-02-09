class Solution {
    public:
        
        void BFS(int src,vector<vector<int>>& rooms,vector<bool>& vis)
        {
            queue<int> q;
            q.push(src);
            vis[src]=true;
            while(!q.empty())
            {
                int parent= q.front();
                q.pop();
                for(auto child: rooms[parent])
                {
                    if(vis[child]==false)
                    {
                        q.push(child);
                        vis[child]=true;
                    }
                   
                }
            }
        }
        bool canVisitAllRooms(vector<vector<int>>& rooms) { //adjacency list
            int n=rooms.size();
            vector<bool>vis(n,false);
            BFS(0,rooms,vis);
           
            auto it=find(vis.begin(), vis.end(),false); // O(n) complexity
            if(it!=vis.end())
                return false;
            else
                return true;
        }
    };
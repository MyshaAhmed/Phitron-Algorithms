class Solution {
    public:
        int n,m;
        bool vis[15][15];
        vector<pair<int,int>> d ={{0,1},{0,-1},{1,0},{-1,0}};
        bool valid(int i,int j)
        {
            if(i<0||i>=n||j<0||j>=m)
                return false;
            return true;
        }
        int dfs(int si,int sj,vector<vector<int>>& grid)
        {
            vis[si][sj]=true;
            int fish=grid[si][sj];
            for(int i=0;i<4;i++)
            {
                int ci=si+d[i].first; // row movement
                int cj=sj+d[i].second; // column movement
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]>0) //valid and not visisted and water--> DFS // water -> DFS
                    fish += dfs(ci, cj, grid);
            }
            return fish;
        }   
        int findMaxFish(vector<vector<int>>& grid) {
                n=grid.size();
                m=grid[0].size();
                int maxCount=0;
                memset(vis,false,sizeof(vis));
                for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                        if(!vis[i][j] && grid[i][j]>0)
                        {
                            int dfscount=dfs(i,j,grid);
                            maxCount=max(dfscount,maxCount);
                        }
                           
    
                return maxCount;
        }
    };
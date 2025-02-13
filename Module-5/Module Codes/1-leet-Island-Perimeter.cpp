class Solution {
    public:
        int n,m;
        int count;
        bool vis[105][105];
        vector<pair<int,int>> d ={{0,1},{0,-1},{1,0},{-1,0}};
        bool valid(int i,int j)
        {
            if(i<0||i>=n||j<0||j>=m)
                return false;
            return true;
        }
        void dfs(int si,int sj,vector<vector<int>>& grid)
        {
            vis[si][sj]=true;
            for(int i=0;i<4;i++)
            {
                int ci=si+d[i].first; // row movement
                int cj=sj+d[i].second; // column movement
                if(!valid(ci,cj)) // not valid--> count  // out of bounds -> perimeter count
                    count++;
                else if( valid(ci,cj) && grid[ci][cj]==0) // valid and water--> count // water cell -> perimeter count
                    count++;
                else if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1) //valid and not visisted and land--> DFS // unvisited land -> DFS
                    dfs(ci,cj,grid);
            }
    
        }
        int islandPerimeter(vector<vector<int>>& grid) {
            n=grid.size();
            m=grid[0].size();
            count=0;
            // grid input:
            memset(vis,false,sizeof(vis));
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(!vis[i][j] && grid[i][j]==1) // not visited and land
                        dfs(i,j,grid);
            return count;
        }
    };
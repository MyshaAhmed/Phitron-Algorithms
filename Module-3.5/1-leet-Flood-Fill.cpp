class Solution {
    public:
        vector<pair<int,int>> d={{0,1},{1,0},{-1,0},{0,-1}};
        bool vis[55][55];
        int n,m;
        bool valid(int i,int j)
        {
            if(i<0||i>=n||j<0||j>=m)
                return false;
            return true;
        }
        void dfs(int sr,int sc,vector<vector<int>>& image,int color,int imageColor)
        {
            vis[sr][sc]=true;
            image[sr][sc]=color;
            for(int i=0;i<4;i++)
            {
                int ci=sr+d[i].first;
                int cj=sc+d[i].second;
                if(valid(ci,cj)&& !vis[ci][cj] && image[ci][cj]==imageColor)
                {
                    dfs(ci,cj,image,color,imageColor);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            n=image.size();
            m=image[0].size();
    
            if(image[sr][sc]==color)
                return image;
            memset(vis,false,sizeof(vis));
            int imageColor=image[sr][sc];
            dfs(sr,sc,image,color,imageColor);
            return image;
        }
    };
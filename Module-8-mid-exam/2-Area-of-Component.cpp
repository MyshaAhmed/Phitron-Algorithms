#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mov={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i, int j) 
{
    if(i<0||i>=n||j<0||j>=m) 
        return false;
    return true;
}

int DFS(int si,int sj) //complexity: O(V+E)= O(nxm)
{
    int area_count=1;
    vis[si][sj]=true;
    for(int i=0;i<4; i++)
    {
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;
        if(valid(ci,cj) &&!vis[ci][cj] && grid[ci][cj]=='.')
            area_count+= DFS(ci,cj);
    }
    return area_count;
}
int main()
{
    cin>>n>>m;
    int cnt=0;
    int min_count=INT_MAX;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='.')
            {
                int area_count=DFS(i,j);
                min_count=min(min_count,area_count);
                cnt++;
            }
        }
    }
    if(cnt>0)
        cout<<min_count<<endl;
    else
        cout<<-1<<endl;
    return 0;
    
}
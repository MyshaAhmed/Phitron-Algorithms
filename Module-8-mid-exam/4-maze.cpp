#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int,int> parent[1005][1005];
vector<pair<int,int>> mov={{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i, int j) 
{
    if(i<0||i>=n||j<0||j>=m) 
        return false;
    return true;
}
void BFS(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0; 
    while(!q.empty())
    {
        pair<int,int> par=q.front();
        q.pop();
        int par_i=par.first;
        int par_j=par.second;
        // cout<<par_i<<" "<<par_j<<endl;
        for(int i=0;i<4; i++)
        {
            int ci=par_i+mov[i].first;
            int cj=par_j+mov[i].second;
            if(valid(ci,cj) &&!vis[ci][cj] && grid[ci][cj]=='.') // only change | grid[ci][cj]=='.'|
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1; //updating level of each node after visiting it.
                parent[ci][cj]={par_i,par_j};
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    int si,sj,di,dj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='R')
            {
                si=i;
                sj=j;
            }
            if(grid[i][j]=='D')
            {
                di=i;
                dj=j;
            }
        }        
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    BFS(si,sj);

    if(vis[di][dj])
    {
        int ci=di;
        int cj=dj;
        while(parent[ci][cj]!={-1,-1})
        {
            
        }
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}
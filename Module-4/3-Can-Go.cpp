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
void DFS(int si,int sj)
{
    vis[si][sj]=true;
    for(int i=0;i<4; i++)
    {
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;
        if(valid(ci,cj) &&!vis[ci][cj] &&(grid[ci][cj]=='.' || grid[ci][cj]=='B'))
            DFS(ci,cj);
    }
}
void BFS(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    while(!q.empty())
    {
        pair<int,int> par=q.front();
        q.pop();
        int par_i=par.first;
        int par_j=par.second;
        for(int i=0;i<4; i++)
        {
            int ci=par_i+mov[i].first;
            int cj=par_j+mov[i].second;
            if(valid(ci,cj) &&!vis[ci][cj] && (grid[ci][cj]=='.' || grid[ci][cj]=='B'))
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    int si=-1,sj=-1,di=-1,dj=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            {
                si=i;
                sj=j;
            }
            if(grid[i][j]=='B')
            {
                di=i;
                dj=j;
            }
        }        
    }
    if(si==-1 || sj==-1||dj==-1||di==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    BFS(si,sj);
    if(vis[di][dj]==false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
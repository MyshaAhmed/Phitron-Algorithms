#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int,int>> mov={{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) 
{
    if(i<0||i>=n||j<0||j>=m) 
        return false;
    return true;
}

void DFS(int si,int sj) //complexity: O(V+E)= O(nxm)
{
    cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i=0;i<4; i++)
    {
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;
        if(valid(ci,cj) &&!vis[ci][cj])
            DFS(ci,cj);
    }
}
void BFS(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0; //initial level of source node is 0.
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
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    cout<<"Output:"<<endl;
    BFS(si,sj);
    cout<<level[di][dj]<<endl;
    return 0;
/*
INPUT:

3 4
....
.#..
.#..
1 2
2 0


3 4
.#..
.#..
.#..
1 2
2 0

Output:
5

-1

*/ 
}
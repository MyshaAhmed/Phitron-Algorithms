#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int,int>> mov={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
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
        for(int i=0;i<8; i++)
        {
            int ci=par_i+mov[i].first;
            int cj=par_j+mov[i].second;
            if(valid(ci,cj) &&!vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1; 
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>>ki>>kj>>qi>>qj;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        BFS(ki,kj);
        if(vis[qi][qj])
            cout<<level[qi][qj]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
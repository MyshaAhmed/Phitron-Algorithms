#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
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
    cnt++;
    vis[si][sj]=true;
    for(int i=0;i<4; i++)
    {
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;
        if(valid(ci,cj) &&!vis[ci][cj] && grid[ci][cj]=='.')
            DFS(ci,cj);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];

    memset(vis,false,sizeof(vis));
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='.')
            {
                cnt=0;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }
    if(v.empty())
    {
        cout<<0<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    for(auto it: v)
        cout<<it<<" ";
    cout<<endl;
    return 0;

}
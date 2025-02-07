#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int,int>> mov={{-1,0},{1,0},{0,-1},{0,1}};

void DFS(int si,int sj)
{
    // cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i=0;i<4; i++)
    {
        int ci=si+mov[i].first;
        int cj=sj+mov[i].second;
        cout<<ci<<" "<<cj<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    cout<<"Output:"<<endl;
    DFS(si,sj);
    return 0;
/*
INPUT:

3 4
....
....
....
1 2

Output:
1 2
0 2
2 2
1 1
1 3
*/ 
}
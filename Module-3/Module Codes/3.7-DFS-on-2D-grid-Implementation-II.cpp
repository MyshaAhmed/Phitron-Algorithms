#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[105][105];
bool vis[105][105];
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
int main()
{
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
0 1
1 1
2 1
2 0
1 0
0 0
2 2
2 3
1 3
0 3
*/ 
}
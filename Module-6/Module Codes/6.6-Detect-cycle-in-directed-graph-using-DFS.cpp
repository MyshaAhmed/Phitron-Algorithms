#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool pathvis[105];
bool vis[105];
bool cycle;

void DFS(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for(auto child:adj_list[src])
    {
        if(vis[child] && pathvis[child])
            cycle = true;
        if(!vis[child])
        {
            DFS(child);
        }
    }
    // return logic:
    pathvis[src] = false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));
    // for disconnected graph:
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        DFS(i);
    }

    if(cycle)
        cout<<"cycle detected"<<endl;
    else
        cout<<"No cycle detected"<<endl;
    return 0;

/* 
Input:
3 3
0 1
1 2
2 0
Output:cycle detected

input:
3 3
0 1
1 2
3 0
Output: No cycle detected
*/ 
}
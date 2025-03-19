/* 
Question: You will be given an undirected graph as input. Then you will be given
a node N. You need to tell the number of nodes that can be visited from node N.
*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];
bool vis[10005];

int dfs(int node)
{
    vis[node] = true;
    int count = 1;  
    for(auto child:adj_list[node])
    {
        if(!vis[child])
        {
            count +=dfs(child);
        }
            
    }
    return count;
}
int main()
{
    int n, e,node;
    cin>>n>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cin>>node;
    memset(vis, false, sizeof(vis));
    int count=dfs(node);
    cout<<count<<endl;
    
    return 0;
}
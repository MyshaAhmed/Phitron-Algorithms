/* 
Question: You will be given an undirected graph as input. You need to tell the
number of nodes in each component in ascending order.
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
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
  
    vector<int> components;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            int node_count=dfs(i);
            components.push_back(node_count);
        }
    }
    sort(components.begin(), components.end());
    for(auto it: components)
    {
        cout<<it<<" ";
    }
    return 0;
/* 
input:
10 5
1 2
2 3
1 3
4 0
5 6
*/ 
}
/* 
Question: You will be given an undirected graph as input. You need to tell the
number of components in this graph.
*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];
bool vis[10005];
void dfs(int src)
{
    vis[src] = true;
    for(auto child: adj_list[src])
    {
        if(!vis[child])
            dfs(child);
    } 
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        
    }
    memset(vis, false, sizeof(vis));
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
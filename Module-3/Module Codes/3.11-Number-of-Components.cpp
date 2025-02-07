#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

// use dfs for graph traversal
void DFS(int src) 
{
    // cout<<src<<" ";
    vis[src] = true;
    for(auto child:adj_list[src])
        if(!vis[child])
            DFS(child);
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
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==false)
        {
            DFS(i); // start DFS from node 0
            cnt++;
        }
        // cout<<endl;
    }
    cout<<"Number of connected components: "<<cnt<<endl;
    return 0;
    
/*
INPUT:

8 6
1 2
0 5
2 3
6 7
4 5
1 3


3 4
.#..
.#..
.#..
1 2
2 0

Output:
Number of connected components: 3

*/ 
}
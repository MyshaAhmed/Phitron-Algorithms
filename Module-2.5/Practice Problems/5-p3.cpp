/* 
Question: You will be given an undirected graph as input. Then you will be given
a node N. You need to print the number of nodes that are directly connected to the
node N.
*/ 
/* 
Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.
*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];  //adjacency_list
bool vis_list[10005]; 
int level[10005];

// BFS for shortest path
void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_list[src] = true;
    // parent[src] = -1; na dileo hoy, already -1 diye initialized
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child: adj_list[par])
        {
            if(!vis_list[child])
            {
                vis_list[child] = true;
                q.push(child);
                level[child] = level[par] + 1;  // distance between parent and child is 1 more than parent's distance
            }
        }
    }  
}
int main()
{
    // Graph input:
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    BFS(0);
    int node;
    cin>>node;
    memset(vis_list, false, sizeof(vis_list));
    int count = 0;
    for(auto x: adj_list[node])
    {
        count++;
    }
    cout<<count<<endl;
    return 0;
}
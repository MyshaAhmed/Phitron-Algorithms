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
    level[src] =0;
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
    // query:
    int q;
    cin>>q;
    while(q--)
    {
        memset(vis_list, false, sizeof(vis_list));
        memset(level,-1, sizeof(level)); // initialize level with -1
        int s, d;
        cin>>s>>d;
        BFS(s);
        cout<<"o/p: ";
        cout<<level[d]<<endl;
        
    }
    return 0;
}
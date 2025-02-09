/* 
Question: You will be given an undirected graph which will be connected as input.
Then you will be given a level L. You need to print the node values at level L in
descending order. The source will be 0 always.
*/ 

/* 
Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.
*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10005];  //adjacency_list
bool vis_list[10005]; 
int level[10005];
vector<int>level_nodes;
int L;

// BFS for shortest path
void BFS(int src,int L)
{
    queue<int> q;
    q.push(src);
    vis_list[src] = true;
    level[src] = 0;  // Start level from 0
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        if (level[par] == L) {
            level_nodes.push_back(par);
        }
        for(auto child: adj_list[par])
        {
            if(!vis_list[child])
            {
                level[child] = level[par] + 1; 
                vis_list[child] = true;
                q.push(child);
                
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
    
    memset(vis_list, false, sizeof(vis_list));
    memset(level,-1, sizeof(level)); // initialize level with -1
    
    cin>>L;
    BFS(0,L); 
    
    sort(level_nodes.begin(), level_nodes.end(), greater<int>());  // sort in descending order
    for(auto i: level_nodes)
        cout<<i<<" ";
    cout<<endl;
    

    return 0;
}
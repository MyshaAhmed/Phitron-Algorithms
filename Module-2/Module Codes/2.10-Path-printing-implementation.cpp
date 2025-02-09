#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis_list[1005];
int level[1005];
int parent[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_list[src] = true;
    level[src] = 0;
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
                level[child] = level[par] + 1; // increment level by 1 for each child node in BFS traversal
                parent[child] = par; 
            }
        }
    }  
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
        adj_list[b].push_back(a); // for undirected graph
    }
    memset(vis_list, false, sizeof(vis_list)); // initialize all nodes as unvisited
    memset(level,-1, sizeof(level)); // initialize level with -1
    memset(parent,-1, sizeof(parent)); // initialize parent with -1
    int src,dest;
    cin>>src>>dest;
    BFS(src);
    cout<<"shortest distance between src to dest: ";
    cout<<level[dest]<<endl;
    // for path from source to destination
    int node=dest;
    vector<int> path;
    while(node!=-1) // or while(node!=src) for path from source to destination
    {
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end()); // reverse the path for source to destination
    cout<<"path from src to dest: ";
    for(auto x: path)
        cout<<x<<" ";
    cout<<endl;
    return 0;
/*
INPUT:

7 7
0 1
1 3 
1 4 
3 2
4 6
3 5
4 5
0 4

7 7       
0 1
1 3 
1 4 
3 2
4 6
3 5
4 5
0 9


OUTPUT:
shortest distance between src to dest: 2
path from src to dest: 0 1 4

shortest distance between src to dest: -1
path from src to dest: 9

*/ 
}
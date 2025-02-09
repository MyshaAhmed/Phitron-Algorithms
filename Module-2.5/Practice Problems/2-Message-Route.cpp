#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis_list[100005];
int parent[100005];

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
                parent[child] = par; 
            }
        }
    }  
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis_list, false, sizeof(vis_list));
    memset(parent, -1, sizeof(parent));
    int src=1,dest=n;
    BFS(src);
    
    int node=dest;
    vector<int> path;
    while(node!=-1) // or while(node!=src) for path from source to destination
    {
        path.push_back(node);
        node=parent[node];
    }
    if(parent[dest]==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    reverse(path.begin(),path.end()); // reverse the path for source to destination
    cout<<path.size()<<endl;
    for(auto x: path)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
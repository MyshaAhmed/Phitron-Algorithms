#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis_list[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis_list[src] = true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(auto child: adj_list[parent])
        {
            if(!vis_list[child])
            {
                vis_list[child] = true;
                q.push(child);
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
    int src,dest;
    cin>>src>>dest;
    BFS(src);
    if(vis_list[dest])
        cout<<"connected "<<endl;
    else
        cout<<"not connected"<<endl;
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
connected 

not connected

*/ 
}
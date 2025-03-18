/* 
1. Find out what is the shortest distance between 0 to 3 using BFS.
*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
int vis[1005];
int level[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(auto child: adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                level[child]=level[par]+1;
                vis[child]=true;
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
        adj_list[b].push_back(a);
    }
    // printing check====>
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<" -> ";
    //     for(auto x: adj_list[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));

    BFS(0);
    
    cout<<"Shortest distance from 0 to 3 is: "<<level[3]<<endl;
    return 0;
}
    
/* 
input:
7 8
0 5
5 1
1 6
1 4
4 6
3 6
3 2
2 4

output:
Shortest distance from 0 to 3 is: 4
*/ 
    
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty())
    {
        // node ber kore anbo
        int par = q.front();
        q.pop();
        //  node niye kaaj
        cout << par << " ";
        //  children push korbo
        for(auto child: adj_list[par])
        {
            if(!vis[child]) // if(vis[child]==false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    // // print new line after BFS traversal
    // cout << endl;
    // return; // return from the function BFS() to avoid unnecessary computation if you don't want to continue further BFS traversal after this function call.
}
int main()
{
    // adjacency list:
    int n,e;
    cin >> n >> e;
    // vector<vector<int>> adj_list[n]; // array of vectors   ---> declare it globally
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b); // add b to a's list
        adj_list[b].push_back(a); // add a to b's list (for undirected graph)
    }
    // initialize visited array to false using memset function
    memset(vis, false, sizeof(vis));
    cout<<"Output:"<<endl;
    // perform BFS traversal from node 0
    BFS(0); // start from node 1 (or any other node)
    cout << endl;
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

OUTPUT:
0 1 3 4 2 5 6
*/ 
}
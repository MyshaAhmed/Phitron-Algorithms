#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected
    }
    // print adj_list:
    cout<<"Adjacency List:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<i<<" -> ";
        for(auto it: adj_list[i])
            cout<<it<<" ";
        cout<<endl;
    }
/*
INPUT:

5 5
0 1
0 2 
3 0 
1 3
3 4

OUTPUT:
Adjacency List:
0 -> 1 2 3 
1 -> 0 3
2 -> 0
3 -> 0 1 4
4 -> 3
*/ 
    return 0;
}
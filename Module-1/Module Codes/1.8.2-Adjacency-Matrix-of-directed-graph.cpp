#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));
    
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1; // only change in directed graph 
    }
    // set diagonal elements to 1
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i==j)  // if diagonal element, mark it as 1
                adj_mat[i][j] = 1;

    // print adjacency matrix
    cout<<"Adjacency Matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<adj_mat[i][j]<<" ";
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
Adjacency Matrix:
1 1 1 1 0
1 1 0 1 0
1 0 1 0 0
1 1 0 1 1
0 0 0 1 1
*/ 
    return 0;
}
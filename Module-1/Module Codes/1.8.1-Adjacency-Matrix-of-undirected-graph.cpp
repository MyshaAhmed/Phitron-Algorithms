#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int adj_mat[n][n];
    // Initialize adjacency matrix with 0s===> 2 ways: for loop and memset
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         adj_mat[i][j] = 0;

    // we will initialize the matrix with 0 using memset
    memset(adj_mat, 0, sizeof(adj_mat));
    
    // Now, we will take input for the edges and mark them in the adjacency matrix
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1; // a is connected to b
        adj_mat[b][a] = 1; // b is also connected to a
    }
    // set diagonal elements to 1
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i==j)  // if diagonal element, mark it as 1
                adj_mat[i][j] = 1;

    // Now, we will print the adjacency matrix
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
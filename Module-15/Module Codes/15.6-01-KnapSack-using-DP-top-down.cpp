#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];
int knapsack(int i, int mx_weight)
{
    // base case
    if(i<0 || mx_weight<=0 )
        return 0;
    if(dp[i][mx_weight]!=-1)
        return dp[i][mx_weight];

    if(weight[i]<=mx_weight) 
    {
        // 2 options
        // 1. bag a rakhbo 2. bag a rakhbona
        int op1=knapsack(i-1, mx_weight-weight[i])+ val[i];
        int op2=knapsack(i-1, mx_weight);
        dp[i][mx_weight] = max(op1, op2); // store the result
        return dp[i][mx_weight] ;
    }
    else
    {
        // 1 option
        // bag a rakhte parbo na
        dp[i][mx_weight] = knapsack(i-1, mx_weight);
        return dp[i][mx_weight] ;
    }
    
}
int main()
{
    
    int n,mx_weight;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    cin>>mx_weight;
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1; // initialize all values with -1
        
    cout<< knapsack(n-1,mx_weight); // last value for top down approach in recursion---> knapsack

    return 0;
/* 
input:
n
val
weight
4
10 4 7 5    
4 3 2 5
8
Output:
17
*/ 
}
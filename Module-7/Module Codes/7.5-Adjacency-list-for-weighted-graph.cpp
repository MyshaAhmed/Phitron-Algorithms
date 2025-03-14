#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int, int>> adj_list[n];
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c}); // for directed weighted graph
        adj_list[b].push_back({a, c}); // for undirected weighted graph
    }
    // printing adj_list:
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto it : adj_list[i])
            cout << "(" << it.first << ", " << it.second << ") ";
        cout << endl;
    }
/* 
Input:
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

Output:
0 -> (1, 10) (2, 7) (3, 4) 
1 -> (0, 10) (2, 1) (4, 3)
2 -> (1, 1) (0, 7) (3, 1) (4, 5)
3 -> (0, 4) (2, 1) (4, 5)
4 -> (3, 5) (1, 3) (2, 5)
*/  
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> edge_list; // vector of pair
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a,b});
    }
    // print edge list:
    cout<<"edge list"<<endl;
    for(auto x: edge_list) 
        cout << x.first << " " << x.second << endl;

    return 0;
/*
INPUT:

5 5
0 1
0 2 
3 0 
1 3
3 4

OUTPUT:
edge List:
0 -> 1 2 3 
1 -> 0 3
2 -> 0
3 -> 0 1 4
4 -> 3
*/ 
}
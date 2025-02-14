#include <bits/stdc++.h>
using namespace std;
int main()
{
    // max priority queue:
    priority_queue<int> p1;

    // min priority queue:
    priority_queue<int,vector<int>,greater<int>> p2;

    // Max priority queue of pairs:
    priority_queue<pair<int, int>> p3;

    // Min priority queue of pairs:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({10,1});
    pq.push({5,2});
    cout<<pq.top().first<<" "<<pq.top().second<<endl; // pq priorotizes according to the first value, whhich is the value of node
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int n, e;
vector<Edge> edgeList;
int dis[1005]; 
void bellman_ford()
{
    for(int i = 0; i < n-1; i++) // [n-1 times bellman ford chalabo]
    {
        for(auto ed: edgeList)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if(dis[a]!=INT_MAX && dis[a]+c<dis[b])
            {
                dis[b] = dis[a]+c;
            }
        }
    }
    bool cycle = false;
    for(auto ed: edgeList) // extra 1 iteration for cycle detection
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if(dis[a]!=INT_MAX && dis[a]+c<dis[b])
        {
            cycle = true;
            break;
        }
    }
    if(cycle)
        cout<<"Negative weighted cycle detected"<<endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout <<  i << " -> " << dis[i] << endl;
    }
}
int main()
{
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
        // edgeList.push_back(Edge(b, a, c));  undirected 
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    bellman_ford();

    return 0;

/* 
input:
-------
node edge
node edge cost
4 4
0 1 5
1 2 3
2 3 2
3 1 -6
---> this graph contains negative weighted cycle
output:
-------
0 -> 0
1 -> 7
2 -> 5
3 -> 10

*/ 
}
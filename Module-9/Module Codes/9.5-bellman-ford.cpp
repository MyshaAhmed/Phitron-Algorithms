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
    // printing distance array:
    for (int i = 0; i < n; i++)
    {
        cout <<  i << " -> " << dis[i] << endl;
    }
    
 
    return 0;

/* 
input:
-------
node edge
node edge cost
4 4
0 2 5
0 3 12
2 1 2
1 3 3

-ve weighted cycle:
4 4
0 1 5
1 2 3
2 3 2
3 1 -6

output:
-------
0 -> 0
1 -> 7
2 -> 5
3 -> 10


-ve:
0 -> 0
1 -> 2
2 -> 6
3 -> 8
*/ 
}
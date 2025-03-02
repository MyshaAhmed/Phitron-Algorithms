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
bool cycle = false;
vector<Edge> edgeList;
long long dis[100005]; 
void bellman_ford(int src)
{
    dis[src] = 0;
    for(int i = 1; i <= n-1; i++) // [n-1 times bellman ford chalabo]
    {
        for(auto ed: edgeList)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
            {
                dis[b] = dis[a]+c;
            }
        }
    }
    for(auto ed: edgeList) // extra 1 iteration for cycle detection
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
        {
            cycle = true;
            break;
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
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src,t;
    cin >> src>>t;
    bellman_ford(src);
    if(cycle)
    {
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }
    while(t--)
    {
        int d;
        cin >> d;
        if(dis[d]==LLONG_MAX)
            cout<<"Not Possible"<<endl;
        else
            cout<<dis[d]<<endl;
            
    }
    return 0;


}
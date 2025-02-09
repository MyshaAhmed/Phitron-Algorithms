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
        adj_list[b].push_back(a); 
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        vector<int>v;
        if(adj_list[x].empty())
        {
            cout<<-1<<endl;
            continue;
        }
        for(auto it: adj_list[x])
            v.push_back(it);
        sort(v.begin(), v.end(),greater<int>());
        for(auto it: v)
            cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}
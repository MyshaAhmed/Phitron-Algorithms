#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector< long long int> v(n);
    vector< long long int> prefix(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 1; i <= n; i++)
       prefix[i] =v[i]+prefix[i-1];
    
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
    
    
    return 0;
}

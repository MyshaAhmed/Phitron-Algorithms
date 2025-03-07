/* 
int l=0, r=n-1;
        long long amount=0;
        int contain_l=0,contain_r=0;
        while(l<r)
        {
            long long min_h2=min(h[l],h[r]);
            long long width=r-l;
            long long curr_amount=min_h2*width;
            if(curr_amount>amount)
            {
                amount=curr_amount;
                contain_l=l;
                contain_r=r;
            }
            if(h[l]<=h[r])
                l++;
            else
                r--;
        }
        cout<<contai
*/ 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> h;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            h.push_back({x,i});
        }
        sort(h.begin(),h.end(),greater<pair<int,int>>());
        int f=h[0].second;
        int s=h[1].second;
        if(f>s)
            swap(f,s);
        cout<<f<<" "<<s<<endl;
    }

    return 0;
}
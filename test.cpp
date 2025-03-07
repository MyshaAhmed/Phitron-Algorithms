#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{  
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector <pair<int,int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }

        sort(arr.rbegin(),arr.rend());
        int idx1 = arr[0].second;
        int idx2 = arr[1].second;

        if (idx1 > idx2) 
            swap(idx1, idx2);
        
        cout <<idx1 <<" " <<idx2 << "\n";
        
        
    }
    
}
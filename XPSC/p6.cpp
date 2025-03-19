#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string str, str2;
        cin >> str >> str2;
        vector<long long> subs(3,0);
        for(auto ch: str)
            for(int i=2; i>=0; i--)
            {
                if(ch==str2[i])
                {
                    if(i==0)
                        subs[i]+=1;
                    else
                        subs[i]+=subs[i-1];
                }
            }
        cout << subs[2] << endl;
        // cout << subs[1] << endl;
        // cout << subs[0] << endl;
    }
    return 0;
}
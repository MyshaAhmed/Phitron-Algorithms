#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        int sz1 = str1.length();
        int sz2 = str2.length();
        if(sz1!=sz2)
            cout<<"NO"<<endl;
        else
        {
            sort(str1.begin(), str1.end());
            sort(str2.begin(), str2.end());
            if(str1==str2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
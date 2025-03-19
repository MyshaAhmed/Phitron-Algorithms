#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str, str2="";
        cin>>str;
        for (size_t i = 0; i < str.length(); i += 2) {
            char ch = str[i];
            int num = str[i + 1] - '0';
            if (num != 0) 
                str2.append(num, ch);
        }
        cout<<str2<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string word;
    char ar[str.size() + 1];
    while(ss>> word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            ar[i] = word[i];
        }
        
    }
    for(int i = 0; i < str.size(); i++)
    {
        cout << ar[i];
    }
    return 0;
}
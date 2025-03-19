#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin >> t;  
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n - 2);
        long long sum = 0; 
        for (int i = 0; i < n - 2; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        long long int main_sum;
        cin >> main_sum;  
        long long num = main_sum - sum;
        cout << num+1<< endl;
    }




    return 0;
}
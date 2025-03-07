#include <bits/stdc++.h>
using namespace std;
int fibo(int n) // complexity= O(2^n)
{
    if(n<=1) // or  if(n==0 || n==1) or if(n<2)
        return n;
    return fibo(n-1) + fibo(n-2);
}
int main()
{
    cout<<fibo(5);
    return 0;
}
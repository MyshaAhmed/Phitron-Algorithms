#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int dp[N];
bool canReach(int target) //
{
    if (1 == target)
        return true;
        
    if (1 > target)
        return false;
    
    if (target >= N) // Prevent out-of-bounds access
        return false;
    if (dp[target] != -1 && target > 0)
        return dp[target]; // 1/0

    bool flag = false;
    if (target % 2 == 0)
    {
        flag = canReach(target / 2);
    }
    bool flag2 = false;
    if (target > 3)
    {
        flag2 = canReach(target - 3);
    }
    dp[target] = flag2 || flag; // recursive call
    return dp[target];
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    if (canReach(n))
    {
        cout << "YES" << endl; // YES
    }
    else
    {
        cout << "NO" << endl; // NO
    }

    return 0;
}
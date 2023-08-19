#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll minOperations(ll n)
{
    vector<ll> dp(n + 1, 0);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
    }
    return dp[n];
}

int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cout << minOperations(i) << endl;
    }
    
    return 0;
}
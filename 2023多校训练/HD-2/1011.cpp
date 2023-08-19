#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

long double verify(int n, int k)    // verify
{
    long double res = 0;
    for (int i = k; i < n; i++)
    {
        res += (long double)1.0 / i;
    }
    return (long double)k / n * res;
}

void solve()
{
    long double n;
    cin >> n;
    if(n == 1 || n == 2)
    {
        cout<<"0\n";
        return;
    }
    int rawAns = (int)round((long double)1 / (long double)M_E * n);
    int ans;
    long double v1 = verify(n,rawAns - 1), v2 = verify(n, rawAns), v3 = verify(n, rawAns + 1);
    if(v1 > v2)
    {
        if(v1 > v3)
        {
            ans = rawAns - 1;
        }
        else
        {
            ans = rawAns + 1;
        }
    }
    else
    {
        if(v2 > v3)
        {
            ans = rawAns;
        }
        else
        {
            ans = rawAns + 1;
        }
    }

    cout<<ans<<'\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
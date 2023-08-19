// m ^ (n - k)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MO = 998244353;
using ll = long long;
typedef unsigned long long ull;

ull mul(ull a, ull b, ull p = MO)
{
    a %= p,b %= p;
    ull c = (long double)a * b / p;
    ull x = a * b, y = c * p;
    long long ans = (long long)(x % p) - (long long)(y % p);
    if(ans < 0) ans += p;
    return ans;
}

int power(ll a, ll b, int p = MO)
{
    int ans = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = mul(ans,a,p);
        a = mul(a,a,p);
    }
    return ans;
}


void solve()
{
    ll n,m,k;cin>>n>>m>>k;
    cout<<power(m,n-k)<<'\n';
}

int main()
{
    int T;cin>>T;
    while (T--)
    {
        solve();
    }
    
}
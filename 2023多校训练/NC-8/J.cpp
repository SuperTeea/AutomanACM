#include <iostream>
#include <vector>
using namespace std;
const int MO = 998244353;
const int p = MO;
using ll = long long;
typedef unsigned long long ull;

const ll N = 1e6 + 10;
ll fac[N];
ll modn[N];
ll modfac[N];
ll ba[N];
void init()
{
    modn[1] = 1;
    modfac[0] = 1;
    fac[0] = 1;
    for (int i = 2; i < N; i++)
    {
        modn[i] = (p - p / i) * modn[p % i] % p;
    }
    for (int i = 1; i < N; i++)
    {
        modfac[i] = modfac[i - 1] * modn[i] % p;
        fac[i] = fac[i - 1] * i % p;
    }
}

ll C(ll n, ll m)
{
    return ((fac[n] * modfac[m] % p) * modfac[n - m]) % p;
}

ull mul(ull a, ull b, ull p = MO)
{
    a %= p, b %= p;
    ull c = (long double)a * b / p;
    ull x = a * b, y = c * p;
    long long ans = (long long)(x % p) - (long long)(y % p);
    if (ans < 0)
        ans += p;
    return ans;
}

int power(ll a, ll b, int p = MO)
{
    int ans = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = mul(ans, a, p);
        a = mul(a, a, p);
    }
    return ans;
}

int main()
{
    init();
    int n,k;
    cin>>n>>k;
    ll tmp = (C(n, k) * fac[k-1]) % p;
    cout<< tmp ;
}

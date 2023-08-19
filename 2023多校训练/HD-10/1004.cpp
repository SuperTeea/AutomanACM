#include <iostream>
#include <vector>
using namespace std;
const int MO = 998244353;
const int p = 998244353;
int pow1(int a, int b, int p = MO)
{
    int ans = 1 % p;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

void extend_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

int mod_reverse(int a, int m)
{
    int x, y;
    extend_gcd(a, m, x, y);
    return (m + x % m) % m;
}

void solve()
{
    int n;cin>>n;
    if (n == 1 || n == 2){
        cout << n-1 << '\n';
    }
    else{
        int a = n * 2 - 1;
        int k = mod_reverse(3,MO);
        int ans = ((long long)a * k) % MO;
        cout << ans << '\n';
    }
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MO = 1e9 + 7;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef unsigned long long ull;

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

struct query
{
    int x,l,y;
};


void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> vecK(n + 1),vecB(n + 1),p(n + 1);
    for(int i = 1;i <= n;i++) cin>>vecK[i];
    for(int i = 1;i <= n;i++) cin>>vecB[i];
    for(int i = 1;i <= n;i++) cin>>p[i];
    vector<query> que(q);
    for (int i = 0; i < q; i++) cin>>que[i].x>>que[i].l>>que[i].y;
    for (auto &&q : que)
    {
        ll ans = q.y;
        int next = p[q.x];
        while (q.l--)
        {
            ans = (ll)((ll)ans * vecK[next] % MO) +  vecB[next] % MO;
            next = p[next];
        }
        cout<<ans<<'\n';
    }
    
}

int main()
{
    SPEEDUP
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
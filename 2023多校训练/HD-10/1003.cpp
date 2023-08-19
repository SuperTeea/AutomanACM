#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
const int p = 998244353;
constexpr int N = 1e6 + 10;
int fact[N];

int power(int a, int b, int p)
{
    int ans = 1 % p;
    for(;b;b >>= 1)
    {
        if(b & 1) ans = (long long) ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

void init()
{
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < N;i++)
        fact[i] = (long long)fact[i - 1] * i % p;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    ll answer=0;
    answer+=fact[n];
    answer+=(k-1)*fact[n]*(power(2,n-2,p)-1);
    cout<<answer%p<<endl;
}

int main()
{
    init();
    int T;cin>>T;
    while(T--) solve();
}
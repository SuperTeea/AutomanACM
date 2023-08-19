#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const int MO = 998244353;
const int p = 998244353;
const ll N = 1e6 +10;
ll fac[N];
ll modn[N];
ll modfac[N];
ll ba[N];
void init(){
    modn[1] = 1;
    modfac[0] = 1;
    fac[0] = 1;
    for (int i = 2;  i < N; i++){
        modn[i] = (p - p /i) * modn[p%i] % p;
    }
    for (int i = 1; i < N; i++){
        modfac[i] = modfac[i-1] * modn[i] % p;
        fac[i] = fac[i-1]*i%p;
    }
}


int pow1(int a,int b , int p = MO)
{
    int ans = 1 % p;
    for(;b;b>>=1)
    {
        if(b & 1) ans = (long long)ans * a % p;
        a = (long long) a * a % p;
    }
    return ans;
}

ll C(ll n, ll m)
{
    return ((fac[n] * modfac[m] % p) * modfac[n-m])%p;
}

void extend_gcd(int a,int b , int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_gcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - (a/b) * y;
}

int mod_reverse(int a, int m)
{
    int x,y;
    extend_gcd(a,m,x,y);
    return (m + x % m) % m;
}

void setba(int x, int n){
    ba[0] = 1;
    for (int i = 1; i <= n; i++){
        ba[i] = ba[i-1] * x;
        ba[i] %= MO;
    }
}


void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    ll zi = 0;
    int demon = pow1(b,n);
    ll km = 0;
    ll ka = 1;
    setba(b-a,n);
    for (int  k = 1; k <= n; k++)
    {
        ll tmpzi = C(n,k);
        //cout << 'C' << " " << tmpzi << '\n';
        km += pow1(k,m); 
        km %= MO;
        tmpzi *= km;
        tmpzi %= MO;
        //cout << 'C' << " " << tmpzi << '\n';
        ka *= a;
        ka %= MO;
        tmpzi *= ka;
        tmpzi %= MO;
        tmpzi *= ba[n-k];
        tmpzi %= MO;
        zi += tmpzi;
        zi %=MO;
        //cout << 'C' << " " << tmpzi << '\n';
    }
    int k = mod_reverse(demon,MO);
    ll aa = ((ll)zi * k) % MO;
    cout<<aa<<'\n';
}

int main()
{
    int T;
    cin>>T;
    init();
    while (T--)
    {
        solve();
    }
    
}
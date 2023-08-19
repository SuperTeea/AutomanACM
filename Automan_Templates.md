# 这是 ___提瓦特大陆的光之队___ 的模板

## MillerRabin & Rho 附带了快速幂 判素数 分解质因数

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
long long max_factor, n;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long quick_pow(long long x, long long p, long long mod) {  // 快速幂
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (__int128)ans * x % mod;
    x = (__int128)x * x % mod;
    p >>= 1;
  }
  return ans;
}

bool Miller_Rabin(long long p) {  // 判断素数
  if (p < 2) return 0;
  if (p == 2) return 1;
  if (p == 3) return 1;
  long long d = p - 1, r = 0;
  while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
  for (long long k = 0; k < 10; ++k) {
    long long a = rand() % (p - 2) + 2;
    long long x = quick_pow(a, d, p);
    if (x == 1 || x == p - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = (__int128)x * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return 0;
  }
  return 1;
}

long long Pollard_Rho(long long x) {
  long long s = 0, t = 0;
  long long c = (long long)rand() % (x - 1) + 1;
  int step = 0, goal = 1;
  long long val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {  // 倍增优化
    for (step = 1; step <= goal; ++step) {
      t = ((__int128)t * t + c) % x;
      val = (__int128)val * abs(t - s) % x;
      if ((step % 127) == 0) {
        long long d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    long long d = gcd(val, x);
    if (d > 1) return d;
  }
}

void fac(long long x) {
  if (x <= max_factor || x < 2) return;
  if (Miller_Rabin(x)) {              // 如果x为质数
    max_factor = max(max_factor, x);  // 更新答案
    return;
  }
  long long p = x;
  while (p >= x) p = Pollard_Rho(x);  // 使用该算法
  while ((x % p) == 0) x /= p;
  fac(x), fac(p);  // 继续向下分解x和p
}

int main() {
  scanf("%d", &t);
  while (t--) {
    srand((unsigned)time(NULL));
    max_factor = 0;
    scanf("%lld", &n);
    fac(n);
    if (max_factor == n)  // 最大的质因数即自己
      printf("Prime\n");
    else
      printf("%lld\n", max_factor);
  }
  return 0;
}
```

## 快速幂 32 位

```cpp
#include <iostream>

int qpower(int a, int b, int p = 1000000007)
{
    int ans = 1 % p;
    while (b)
    {
        if(b & 1) ans = (long long) ans * a % p;
        a = (long long) a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a,n,p;
    std::cin>>a>>n>>p;
    std::cout<<qpower(a,n,p);
}
```

## 同余逆元

```cpp
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
```

## 快读

```cpp
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

#define gc getchar
template <typename T>
inline void read(T &x){
    x=0;bool y=0;char c=gc();while(c<'0'||c>'9'){if(c=='-') y=1;c=gc();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();} if(y) x=-x;
}

```

## 组合数

```cpp
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
```
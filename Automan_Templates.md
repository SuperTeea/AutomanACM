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

## 二分

```cpp
int find() {
  int l = 1, r = 1e9 + 1; // 左闭右开 注意
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}
```

## 矩阵

```cpp
struct mat {
  LL a[sz][sz];

  mat() { memset(a, 0, sizeof a); }

  mat operator-(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) {
        res.a[i][j] = (a[i][j] - T.a[i][j]) % MOD;
      }
    return res;
  }

  mat operator+(const mat& T) const {
    mat res;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) {
        res.a[i][j] = (a[i][j] + T.a[i][j]) % MOD;
      }
    return res;
  }

  mat operator*(const mat& T) const {
    mat res;
    int r;
    for (int i = 0; i < sz; ++i)
      for (int k = 0; k < sz; ++k) {
        r = a[i][k];
        for (int j = 0; j < sz; ++j)
          res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= MOD;
      }
    return res;
  }

  mat operator^(LL x) const {
    mat res, bas;
    for (int i = 0; i < sz; ++i) res.a[i][i] = 1;
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j) bas.a[i][j] = a[i][j] % MOD;
    while (x) {
      if (x & 1) res = res * bas;
      bas = bas * bas;
      x >>= 1;
    }
    return res;
  }
};

```

### 最短路 Dijkstra

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long 
const int maxx = 1e17;
// 给一张图 输出 1 - n 的最短路

struct node
{
    int dis,u;
    bool operator>(const node& a) const { return dis > a.dis; }
};

signed main()
{   
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<int> dis(n,maxx),ptr(n,-1),vis(n);
    priority_queue<node,vector<node>,greater<node>> q;
    for(int i = 0; i < m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dis[0] = 0;
    q.push({0,0});  // index starts from zero
    while (!q.empty())
    {
        int d = q.top().dis;
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto&& [v,w] : adj[u])
        {
            if(vis[v]) continue;
            if(w + d < dis[v])
            {
                dis[v] = w + d;
                ptr[v] = u;
                q.push({dis[v],v});
            }
        }
    }
    if(ptr[n - 1] == -1)
    {
        cout<<-1;
        return 0;
    }
    vector<int> ans;
    ans.push_back(n);
    for(int i = ptr[n - 1];i != -1;i = ptr[i])
        ans.push_back(i + 1);
    for(auto beg = ans.rbegin();beg != ans.rend();beg++)
        cout<<*beg<<' ';
}
```

### 最小生成树 Kruskal

```cpp
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
// 输出最小生成树的边权和 Kruskal 算法

int find(int x,vector<int> & ufs)
{
    if(ufs[x] == x) return x;
    return ufs[x] = find(ufs[x],ufs);
}

void merge(int x,int y,vector<int>& ufs)
{
    ufs[find(y,ufs)] = find(x,ufs);
}

int main()
{
    int n;cin>>n;
    int wei = 0,cnt = 0;
    vector<int> ufs(n);
    vector<pair<int,pair<int,int>>> rec;
    iota(ufs.begin(),ufs.end(),0);
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
        {
            cin>>v[i][j];
            if(i != j) rec.push_back(make_pair(v[i][j],make_pair(i,j)));
        } 
    
    sort(rec.begin(),rec.end());
    reverse(rec.begin(),rec.end());
    while (rec.size() && cnt < n)
    {
        int w,u,v;
        w = rec.back().first;
        u = rec.back().second.first;
        v = rec.back().second.second;
        if(find(u,ufs) != find(v,ufs))
        {
            merge(u,v,ufs);
            wei += w;
        }
        rec.pop_back();
    }
    cout<<wei;
}
```

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
constexpr int N = 1e6 + 10;
constexpr int MOD = 998244353;
using ll = long long;
vector<bool> isPrime(N,true);
vector<int> prime;

void initPrime()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            if ((long long)i * i <= N)
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
        }
    }
}

void solve()
{
    ll n;cin>>n;
    // n %= MOD;
    vector<ll> factors;
    set<ll> cnt;
    int i = 0,len = prime.size();
    if(n <= 3)
    {
        cout<<n<<" ";
        return;
    }
    while (n > 1 && i < len)
    {
        if((n % prime[i]) == 0)
        {
            n /= prime[i];
            cnt.insert(prime[i]);
            if(cnt.size() > 1) break;
        } 
        else 
        {
            i++;
        }
    }
    
    if(cnt.size() > 1)
        cout<<"1 ";
    else
        cout<<(*(cnt.begin())) % MOD<<' ';
}

int main()
{
    initPrime();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
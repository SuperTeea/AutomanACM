#include <iostream>
#include <cstdio>
using namespace std;
const int test_time = 8;

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

bool millerRabin(int n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    int u = n - 1, t = 0;
    while (u % 2 == 0) u /= 2, ++t;
    for (int i = 0; i < test_time; ++i) {
        int a = rand() % (n - 2) + 2, v = qpower(a, u, n);
        if (v == 1) continue;
        int s;
        for (s = 0; s < t; ++s) {
            if (v == n - 1) break;
            v = (long long)v * v % n;
        }
        if (s == t) return 0;
    }
    return 1;
}

int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n;cin>>n;
        if(n <= 0) return 0;
        cout<<(millerRabin(n) ? "yes" : "no" )<<'\n';
    }
    
}
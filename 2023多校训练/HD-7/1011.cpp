#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
const int MO = 1e9 + 7;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef unsigned long long ull;

void solve()
{
    ll x,a,b,opt = 0;
    cin>>x>>a>>b;
    while(x)
    {
        bool b2 = false,b3 = false;
        ll x1 = x - 1;
        if(x <= a) b2 = true;
        ll x2 = (x + a) / 2;
        if(x <= sqrt(x + b)) b3 = true;
        ll x3 = ll(sqrt(x + b));
        x = min(x1,min(x2,x3));
        opt++;
        if(b2 && b3)
        {
            opt += x;
            break;
        }
    }
    cout<<opt<<'\n';
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
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

ll num[10];
void setnum(){
    num[0] = 0;
    for (int i = 1 ; i < 10; i++){
        num[i] = num[i-1] + (pow(10,i) - pow(10,i-1)) * i;
    }
}

void solve()
{
    ll n;
    cin>>n;
    string s = to_string(n);
    int l = s.size();
    ll ans = num[l-1] + (n - pow(10,l-1) + 1) * l;
    cout << ans << '\n';
}

int main()
{
    SPEEDUP
    int T;
    setnum();
    cin >> T;
    while (T--)
    {
        solve();
    }
}
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
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1),b(n);
    a[0] = 0;
    bool fail = 0;
    int maxb = 0;
    for(int i = 0; i < n-1; i++){
        cin >> b[i];
        maxb = max(maxb,b[i]);
        a[i+1] = a[i] ^ b[i];
        if (a[i+1] < a[i]) fail = 1;
    }
    if (fail){
        cout << -1 << '\n';
        return;
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
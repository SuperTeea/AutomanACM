#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

void solve()
{
    int n;
    cin >> n;
    int a[5005];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++){
        int Max = a[i];
        for (int j = 0; i+j < n; j++){
            Max = max(Max,a[i+j]);
            if (Max != a[i+j]){
                cnt++;
            }
            else if(j == 1){
                break;
            }
        }
    }
    cout << cnt << '\n';
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
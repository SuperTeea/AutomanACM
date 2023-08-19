#include <iostream>
#include <cmath>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
void solve()
{
    int m,n,d;
    cin>>n>>m>>d;

    
    if(ceill(1.0 * m / n) >= d)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main()
{
    SPEEDUP
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    
}
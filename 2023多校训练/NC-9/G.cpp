#include <iostream>
#include <algorithm>
#define reg register
using namespace std;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
const int MN=60;
ll a[61],tmp[61];
bool flag;
void ins(ll x)
{
    for (reg int i = MN; ~i; i--)
        if (x & (1ll << i))
            if (!a[i])
            {
                a[i] = x;
                cout<<i<<"z"<<endl;
                return;
            }
            else
                x ^= a[i];
    flag = true;
}
bool check(ll x)
{
    for (reg int i = MN; ~i; i--)
        if (x & (1ll << i))
            if (!a[i])
                return false;
            else
                x ^= a[i];
    return true;
}

void solve()
{   
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int number;
        cin>>number;
        ins(number);
    }
    ins(k);
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
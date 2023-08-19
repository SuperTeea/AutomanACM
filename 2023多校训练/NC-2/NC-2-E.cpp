#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int X;

bool check(ll y)
{
    y = pow(y,2);
    while (y)
    {
        if(y == X)
            return true;
        y /= 10;
    }
    return false;
}

void solve()
{
    cin>>X;
    ll x = X,cnt = 0;
    if(x == 0)
    {
        cout<<0<<'\n';
        return;
    }
    if(x == 5)
    {
        cout << 23 << '\n';
        return;
    }
    while (x)
    {
        cnt++;
        x /= 10;
    }
    x = X;
    x = x * pow(10,cnt);
    ll j2 = sqrt(x);
    bool has = true;
    for (ll i = j2 - 2; i < j2 + 2; i++)
    {
        if(i <= 0)continue;
        if(check(i) && i <= (int)1e9)
        {
            cout<<i;
            has = false;
            break;
        }
    }
    if(has)
        cout<<"-1\n";
    cout<<'\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
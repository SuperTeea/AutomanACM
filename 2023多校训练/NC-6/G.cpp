#include <iostream>
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve()
{
    int x,y,z;
    cin>>x>>y>>z;

    int gc = gcd(x,y);
    if(x == 0 || y == 0)
    {
        if(z % max(x,y) == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else if(z % gc == 0 && z != 0) cout<<"YES\n";
    else cout << "NO\n";
    // cout<<(0 % 1);
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    
}
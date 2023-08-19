#include <iostream>
using namespace std;
using ll = long long;

int pow1(int a,int n, int Mo = 998244353)
{
    int base = a;
    int res = 1;
    while (n)
    {
        if(n&1)
            res = ((ll)base * res) % Mo;
        base = ((ll)base * base) % Mo;
        n>>=1;
    }
    return res;
}

void solve()
{
    long long n;
    cin>>n;
    cout<<pow1(2,n-1) - 1<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}
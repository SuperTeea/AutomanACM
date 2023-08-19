#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    if(min(n,m) == 1)
        cout<<(n+m)/2<<'\n';
    else if(n%3==0||m%3==0)cout<<"2\n";
    else cout<<"1\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
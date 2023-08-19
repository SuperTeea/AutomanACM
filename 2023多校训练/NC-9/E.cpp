#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;


void solve()
{
    int n,m;
    cin >> n >> m;
    int x = 0,y = 0,l,k;
    if (n == m){
        x = 0;
        y = 0;
        l = n;
        k = 1;
        cout << "YES\n";
        cout << k << '\n';
        cout << x << ' ' << y << ' ' << l << '\n'; 
    }
    while(x == n && y == m){
        
    }

}


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
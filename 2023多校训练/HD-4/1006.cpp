#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n == 2)
    {
        cout << fixed << setprecision(9) << 1.0 << ' ';
        cout << fixed << setprecision(9) << 1.0 << '\n';
    }
    else
    {
        cout << fixed << setprecision(9) << ((1.0 * (n - 1) * 2) / n) << ' ';
        cout << fixed << setprecision(9) << 2.0 << '\n';
    }
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
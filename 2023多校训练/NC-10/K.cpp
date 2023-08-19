#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 1)
    {
        cout << "1.000000000000\n";
        return 0;
    }
    long double p = (long double)2 / n;
    long double ans = pow(p, m);
    cout << fixed << setprecision(12) << ans << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
const int MO = 1e9 + 7;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef unsigned long long ull;

void solve()
{
    int n;
    bool aOne = true;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp != 1) aOne = false;
    }
    if(aOne)
    {
        if(n % 2)
            cout<<"1\n";
        else 
            cout<<"0\n";
    }
    else
    {
        cout << "499122177\n";
    }
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
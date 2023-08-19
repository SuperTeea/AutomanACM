#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

void solve()
{
    int k,n;
    cin>>k>>n;
    if(!n) cout<<"Bob\n";
    else if(n == k + 1)
        cout << "Bob\n";
    else 
        cout<< "Alice\n";
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
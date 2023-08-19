#include <iostream>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    bool open = false; // 是否前一个是0
    string bs;
    cin >> bs;

    if(n == 1)
    {
        if(k % 2) cout<<"0\n";
        else cout<<"1\n";
        return;
    } 

    bool isAl = true;
    for (int i = 0; i < n; i++)
    {
        if (bs[i] == '0')
        {
            isAl = false;
            break;
        } 
    }

    if(isAl && k == 1)
    {
        bs[n-1] = '0';
        cout << bs << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char &c = bs[i];
        if (k == 0)
            break;

        if (c == '0')
        {
            if (open == false)
            {
                open = true;
            }
            bs[i] = '1';
        }
        else if (c == '1')
        {
            if (open)
            {
                open = false;
                k--;
            }
        }
    }
    cout << bs << '\n';
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
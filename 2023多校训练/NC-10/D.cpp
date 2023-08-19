#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<string> v(n);
    for(int i = 0;i < n;i++) cin>>v[i];
    int cntU = 0,cntC = 0;
    if(m % 2 == 0)
    {
        for(auto&& s : v) cntC += (count(s.begin(), s.end(), '1') - 2);
        if(cntC % 2)
            cout << "Alice\n";
        else
            cout << "Bob\n";
        return 0;
    }

    for(auto&& s : v)
    {
        int cntl = 0,cntr = 0;
        for(int i = 0; i < m / 2;i++) if(s[i] == '1') cntl++;
        for (int i = m / 2 + 1; i < m; i++) if (s[i] == '1') cntr++;
        if(cntl == 1 && cntr == 1 && s[m / 2] == '1') cntU++;
        if(!cntU)
        {
            if (s[m / 2] == '1' && ((cntl == 0) || (cntr == 0))) cntC += (cntr + cntl);
            else cntC += (cntl + cntr + (s[m / 2] == '1') - 2);
        }
    }

    if(cntU)
    {
        if (cntU % 2)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    else
    {
        if (cntC % 2)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}
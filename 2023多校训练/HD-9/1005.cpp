#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void solve()
{
    vector<int> v;
    string s;
    char c;cin>>c;
    cin>>c;
    int cnt = 0;
    while (c != ']')
    {
        if(c == ',') s.push_back(' ');
        else s.push_back(c);
        cin>>c;
    }
    // reverse(s.begin(),s.end());
    istringstream in(s);
    int tmp;
    while(in>>tmp)
    {
        v.push_back(tmp);
    }
    int x,y,cc = 0;
    cin>>x>>y;
    cout<<'[';
    for (int i = 0; i < x; i++)
    {
        cout<<'[';
        for (int i = 0; i < y; i++)
        {
            if(i == y - 1) cout<<v[cc++];
            else
                cout << v[cc++] << ", ";
        }
        if(i == x - 1)cout<<']';
        else cout<<"], ";
    }
    cout << ']';
    cout<<'\n';
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
}
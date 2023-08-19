#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
map<string,int> m;
vector<string> v;
int main()
{
    SPEEDUP
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int c;cin>>c;
        while (c--)
        {
            string s;cin>>s;
            m[s]++;
        }
    }
    
    for (auto &&p : m)
        if(p.second == n) v.push_back(p.first);
    
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto&& s : v)
    {
        cout<<s<<'\n';
    }
}
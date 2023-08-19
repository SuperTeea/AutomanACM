#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
int cnt[1000000];
const int N = 1e6 + 10;
void solve()
{
    
    int n;cin>>n;
    int max = 0,cnt_max = 0,minn = N;
    vector<int> v(n),cnt(n + 1);
    for(int i = 0;i < n;i++) cin>>v[i];
    for (int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
        minn = min(v[i],minn);
    } 
    for (int i = 1; i <= n; i++)
    {
        if(cnt_max < cnt[i])
        {
            cnt_max = cnt[i];
            max = i;
        }
    }
    // sort(v.begin(),v.end());
    if(minn == max)
        cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    SPEEDUP
    int T;cin>>T;
    while(T--) solve();
}
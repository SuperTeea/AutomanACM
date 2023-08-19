#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
const int N = (1 << 30);
void solve()
{
    int n;cin>>n;
    int orSum = 0,maxx = 0,minn = N;
    for(int i = 0 ; i < pow(2,n) - 1 ;i++)
    {
        int tmp;cin>>tmp;
        orSum |= tmp;
        maxx = maxx > tmp ? maxx : tmp;
        minn = minn < tmp ? minn : tmp;
    }
    // cout<<maxx<<' '<<orSum;
    if(maxx != orSum) cout<<-1<<'\n';
    else
    {
        vector<int> v;
        while(maxx)
        {
            v.push_back((maxx & (-maxx)));
            maxx -= (maxx & (-maxx));
        }
        for (int i = 0; i < n - v.size(); i++) cout<<'0'<<" \n"[i == n - 1];
        for(int i = 0; i < v.size();i++) cout<<v[i]<<" \n"[i == v.size() - 1];
    }
}

int main()
{
    SPEEDUP
    int T;cin>>T;
    while(T--) solve();
}
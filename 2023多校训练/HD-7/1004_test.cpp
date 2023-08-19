#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int minn = INT32_MAX;
vector<int> v;

void dfs(int x)
{
    if(x > n) 
    {
        int shink = INT32_MIN;
        for (int i = 0; i < n; i++)
        {
            for(int j = i + 1;j < n;j ++)
            {
                int a,b;
                int cnt[4];
                vector<int> tv(v.begin() + i,v.begin() + j + 1);
                cnt[1] = count(tv.begin(),tv.end(),1);
                cnt[2] = count(tv.begin(),tv.end(),2);
                cnt[3] = count(tv.begin(),tv.end(),3);
                sort(tv.begin(),tv.end());
                if(tv.size() % 2)
                {
                    a = cnt[tv[tv.size() / 2]];
                    // minn = min(a,minn);
                    shink = max(shink,a);
                }
                else
                {
                    a = cnt[tv[tv.size() / 2]];
                    b = cnt[tv[(tv.size() / 2) - 1]];
                    a = max(a,b);
                    // minn = min(a,minn);
                    // maxx = max(a,maxx);
                    shink = max(shink,a);
                }
            }
        }
        minn = min(shink,minn);
        
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        v.push_back(i);
        dfs(x + 1);
        v.pop_back();
    }
}

void solve()
{
    minn = INT32_MAX;
    cin >>n;
    if(n == 1)
    {
        cout<<"1\n";
        return;
    }
    dfs(1);
    cout<<minn<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}
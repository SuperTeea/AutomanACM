#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
bool vis[N];
int ufs[N];

int find(int x)
{
    return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}

void unite(int x,int y)
{
    ufs[find(y)] = find(x);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= N - 1; i++)
    {
        ufs[i] = i;
        vis[i] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        vis[a] = true;
        vis[b] = true;
        unite(a,b);
    }
    
    int num;
    cin >> num;
    int standard;
    int t;
    for (int i = 0; i < num; i++)
    {
        cin>>t;
        if (i = 0){
            standard = find(t);
        }
        if(find(t) != standard)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    
}

int main()
{   
    SPEEDUP
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
}
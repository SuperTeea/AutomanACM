#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
const int MO = 1e9 + 7;
const int N = 1e7;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef unsigned long long ull;
int mem[N];

int calc(int x)
{
    if(mem[x]) return mem[x];
    if(x % 2)
        return mem[x] = (x * (x + 2));
    else return mem[x] = (x * (x + 3));
}

void solve()
{
    int n;
    cin>>n;
    if(n >= 1 && n <= 3){
        cout<<"1\n";
        return;
    } 
    else if(n >= 4 && n <= 10) 
    {
        cout<<"2\n";
        return;
    }
    int l = 1, r = 3e5 + 1; 
    while (l + 1 < r)
    {                          // 如果两点不相邻
        int mid = (l + r) / 2; // 取中间值
        if (calc(mid) < n)        // 如果可行
            l = mid;           // 升高锯片高度
        else
            r = mid; // 否则降低锯片高度
    }
    cout<<l + 1<<'\n';
}

int main()
{
    SPEEDUP
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
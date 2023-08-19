// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef long long ll;
const int N = 1e5 + 10;
// typedef long long int;
string arr[N];
int pa[N];
int Next[N];
int cnt = 0;

// int find(int x)
// {
//     return pa[x] == x ? x : pa[x] = find(pa[x]);
// }

// void unite(int x, int y)
// {
//     pa[find(x)] = find(y);
// }

// bool match(string x, string y){
//     int l = x.size();
//     for (int i = 0; i < l; i++){
//         if (x.substr(i,l - i) == y.substr(0,l - i)){
//             if (i == 0) return 1;
//             else if (x.substr(0,i) == y.substr(l-i,i)) return 1;
//             else continue;
//         }
//         else continue;
//     }
//     return 0;
// }

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int p=1;p<=n;p++)
    {
        string sec;
        cin>>sec;
        int k = 0, i = 0, j = 1;
        while (k < m && i < m && j < m) {
            if (sec[(i + k) % m] == sec[(j + k) % m]) {
                k++;
            } else {
                sec[(i + k) % m] > sec[(j + k) % m] ? i = i + k + 1 : j = j + k + 1;
             if (i == j) i++;
                k = 0;
            }
        }
        i = min(i, j);
        string tmp = sec.substr(i);
        tmp += sec.substr(0,i);
        arr[p] = tmp;
    }
    int Q;
    cin>>Q;
    while (Q--)
    {
        int x,y;
        cin>>x>>y;
        if(arr[x] == arr[y])
            cout<<"Yes\n";
        else   
            cout<<"No\n";
    }
    

}

int main()
{
    SPEEDUP
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

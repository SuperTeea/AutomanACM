// Super-Code! AWA
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef long long ll;
const int N = 1e5 + 10;
pair<int,int> pairs[N];
// typedef long long int;
struct Vertice
{
    int cost;
    // bool isLit = false;  
};
Vertice v[N];
struct edge
{
    int from, to;
    edge(int a, int b)
    {
        from = a;
        to = b;
    }
};
vector<edge> e[N];

// dfs x 为当前节点
int dfs(int x)
{
    if(!e[x].size())    // 此节点没有后续
        return 0;
    int nCost = 0;  // 子节点（不做有子节点的)的开销之和
    int passCost = 0; // 花费
    // dfs 全部子节点
    for (int i = 0; i < e[x].size(); i++)
    {
        int p = e[x][i].to;
        passCost += dfs(p);
        if(!e[p].size()) // 底下还有子节点，那这个一定是亮的
            nCost += v[p].cost;
    }
    
    if(nCost >= v[x].cost) // 点父节点（相同也是)
    {
        return passCost + v[x].cost;
    }
    else
    {
        return passCost + nCost;
    }
    // else    // 点所有子节点 （其实是不用的）
    // {
        // for (int i = 0; i < e[x].size(); i++)
    // }
}

void solve()
{
    int n;
    cin>>n;
    //init
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        v[i].cost = 0;
        // v[i].isLit = false;   
    }
    // 读入开销
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i].cost;
    }

    // 读入边
    for (int i = 0; i < n - 1; i++)
    {
        cin>>pairs[i].first>>pairs[i].second;
    }
    sort(pairs,pairs + n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int &a = pairs[i].first;
        int &b = pairs[i].second;
        // cout<<a<<' '<<b<<'\n';
        e[a].push_back(edge(a,b));
    }
    
    cout<<dfs(1)<<'\n';
    // cout<<'\n';
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
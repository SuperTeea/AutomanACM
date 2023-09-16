#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long 
const int maxx = 1e17;
// 给一张图 输出 1 - n 的最短路

struct node
{
    int dis,u;
    bool operator>(const node& a) const { return dis > a.dis; }
};

signed main()
{   
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<int> dis(n,maxx),ptr(n,-1),vis(n);
    priority_queue<node,vector<node>,greater<node>> q;
    for(int i = 0; i < m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dis[0] = 0;
    q.push({0,0});  // index starts from zero
    while (!q.empty())
    {
        int d = q.top().dis;
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto&& [v,w] : adj[u])
        {
            if(vis[v]) continue;
            if(w + d < dis[v])
            {
                dis[v] = w + d;
                ptr[v] = u;
                q.push({dis[v],v});
            }
        }
    }
    if(ptr[n - 1] == -1)
    {
        cout<<-1;
        return 0;
    }
    vector<int> ans;
    ans.push_back(n);
    for(int i = ptr[n - 1];i != -1;i = ptr[i])
        ans.push_back(i + 1);
    for(auto beg = ans.rbegin();beg != ans.rend();beg++)
        cout<<*beg<<' ';
}

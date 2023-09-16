#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
// 输出最小生成树的边权和 Kruskal 算法

int find(int x,vector<int> & ufs)
{
    if(ufs[x] == x) return x;
    return ufs[x] = find(ufs[x],ufs);
}

void merge(int x,int y,vector<int>& ufs)
{
    ufs[find(y,ufs)] = find(x,ufs);
}

int main()
{
    int n;cin>>n;
    int wei = 0,cnt = 0;
    vector<int> ufs(n);
    vector<pair<int,pair<int,int>>> rec;
    iota(ufs.begin(),ufs.end(),0);
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
        {
            cin>>v[i][j];
            if(i != j) rec.push_back(make_pair(v[i][j],make_pair(i,j)));
        } 
    
    sort(rec.begin(),rec.end());
    reverse(rec.begin(),rec.end());
    while (rec.size() && cnt < n)
    {
        int w,u,v;
        w = rec.back().first;
        u = rec.back().second.first;
        v = rec.back().second.second;
        if(find(u,ufs) != find(v,ufs))
        {
            merge(u,v,ufs);
            wei += w;
        }
        rec.pop_back();
    }
    cout<<wei;
}
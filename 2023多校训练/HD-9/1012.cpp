#include <iostream>
#include <vector>
using namespace std;
vector<vector<char> > datas;
vector<char> person;
int n,m,k;


void solve()
{
    cin>>n>>m>>k;
    vector<int> adj;
    for(int i = 1;i <= k;i++)
    {
        int a,b;
        cin>>a>>b;
        if (b == m)
            adj.push_back(a);
    }

    datas.clear();
    for (int i = 0; i < n; i++)
    {
        vector<char> vtmp;
        for (int j = 0; j < m; j++)
        {
            char tmp;
            cin>>tmp;
            vtmp.push_back(tmp);
        }
        datas.push_back(vtmp);
    }
    person.clear();
    for (int i = 0; i < m - 1; i++)
    {
        char tmp;
        cin >> tmp;
        person.push_back(tmp);
    }
    int otpt = 0;
    int ccnt = 0;
    for (int i = 0; i < 3; i++)
    {
        int cnt = 0;
        
        for (int h = 0; h < n; h++)
        {
            bool ok = 1;
            for (int j = 0; j < adj.size(); j++)
                {
                    if (datas[h][adj[j]] != person[adj[j]])
                    {
                        ok = 0;
                        break;
                    }
                }
            if (ok) cnt++;
        }
        if(cnt > ccnt)
        {
            ccnt = cnt;
            otpt = i;
        }
    }
    cout<<otpt<<'\n';
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
}
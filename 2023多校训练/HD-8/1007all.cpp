#include <bits/stdc++.h>
using namespace std;
int n, m, q, f[100100], c, d, a, b;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
int fd(int x) // 找出x家的大佬 也就是二叉树的祖先节点
{
    if (f[x] == x) // x是x的爸爸，简单的来说就是x没爸爸了

        // 他是家里最大的大佬，所以返回的x就是我们所求的祖先节点
        return x;
    else
        return f[x] = fd(f[x]); // x不是他自己的爸爸，所以他上面还
    // 有爸爸，我们的目标是祖先节点，所以我们此时要做的是问他
    // 爸爸的爸爸是谁，即再使用一次fd（find）函数【其实就是一个递归过程
}
void hb(int x, int y)
{
    f[fd(y)] = fd(x); // 合并x子集和y子集，直接把x子集的祖先节
    // 点与y子集的祖先节点连接起来，通俗点来说就是把x的最大祖
    // 先变成y子集最大祖先的爸爸
    return;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin>>c>>d;
        hb(c, d);
    }
    int k;
    cin>>k;
    int number;
    cin>>number;
    int standard=fd(number);
    if(k==1)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < k-1; i++)
    {
        int q;
        cin>>q;
        if (fd(q) != standard) // 如果a所在子集的大佬[前面已经解释过了]和b所在子集的大佬一样，即可知a和b在同一个集合
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
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
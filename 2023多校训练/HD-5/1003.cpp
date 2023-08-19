#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define RG register
#define MAX 1000100
#define MOD 1000000007
inline int read()
{
    RG int x = 0, t = 1;
    RG char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = -1, ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = x * 10 + ch - 48, ch = getchar();
    return x * t;
}
char ch[MAX], s[MAX];
int n, f[MAX];
struct Palindromic_Tree
{
    struct Node
    {
        int son[26];
        int ff, len;
    } t[MAX];
    int last, tot;
    void init()
    {
        t[tot = 1].len = -1;
        t[0].ff = t[1].ff = 1;
    }
    void extend(int c, int n, char *s)
    {
        int p = last;
        while (s[n - t[p].len - 1] != s[n])
            p = t[p].ff;
        if (!t[p].son[c])
        {
            int v = ++tot, k = t[p].ff;
            t[v].len = t[p].len + 2;
            while (s[n - t[k].len - 1] != s[n])
                k = t[k].ff;
            t[v].ff = t[k].son[c];
            t[p].son[c] = v;
        }
        last = t[p].son[c];
    }
} PT;
int main()
{
    PT.init();
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    if (n & 1)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i += 2)
        s[i] = ch[(i + 1) / 2];
    reverse(&ch[1], &ch[n + 1]);
    for (int i = 2; i <= n; i += 2)
        s[i] = ch[(i + 1) / 2];
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        PT.extend(s[i] - 97, i, s);
        int p = PT.last;
        while (p != 1)
        {
            if (PT.t[p].len % 2 == 0 && PT.t[p].len > 0)
                f[i] = (f[i] + f[i - PT.t[p].len]) % MOD;
            p = PT.t[p].ff;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
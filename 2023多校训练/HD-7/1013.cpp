#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
const int MO = 1e9 + 7;
using ll = long long;
#define SPEEDUP                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
typedef unsigned long long ull;

int crossSearch(int l, int m, int r, vector<int> &v)
{
    vector<int> v1 = v;
    int i = l;
    int j = m + 1;
    int k = 0;
    int s3 = 0;
    while (i <= m && j <= r)
    {
        if (v1[i] > v1[j])
        {
            v[l + k] = v1[j];
            s3 += m - i + 1; // 找到v1[j]在v1中的位置，计算m到i位置的个数
            k++;
            j++;
        }
        else
        {
            v[l + k] = v1[i];
            k++;
            i++;
        }
    }
    if (i <= m)
    { // 当右边遍历完，把左边依次添加到左边,☆此处要注意！赋值给的一定是l+k,因为不加l，则对左数组无影响，对右数组有影响，因为k是相对的
        while (l + k <= r && i <= m)
        {
            v[l + k] = v1[i];
            k++;
            i++;
        }
    }
    else
    { // 当左边遍历完，把右边依次添加到左边
        while (j <= r && k <= r)
        {
            v[l + k] = v1[j];
            k++;
            j++;
        }
    }
    return s3;
}
int partition(int l, int r, vector<int> &v)
{
    if (l >= r)
    {
        return 0;
    }
    int m = (l + r) / 2;
    int s1 = partition(l, m, v);      // 左边的逆序对数
    int s2 = partition(m + 1, r, v);  // 右边的逆序对数
    int s3 = crossSearch(l, m, r, v); // 中间的逆序对数
    int ans = s1 + s2 + s3;

    return ans;
}


void solve()
{
    int number;
    vector<int> v;
    vector<int>b;
    int n;
    cin >> n;
    int min;
    int max;
    int left;
    int right = 0;
    int zuo;
    int you;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        v.push_back(number);
        b.push_back(number);
    }
    for (int i = 0; i < v.size(); i++)
    {
        left = v[i];
        for (int j = v.size() - 1; j > i; j--)
        {
            if (left > v[j])
            {
                if (j - i + 1 > right)
                {
                    right=j-i+1;
                    zuo=i;
                    you=j;
                    break;
                }
            }
        }
    }
    reverse(b.begin()+zuo,b.begin()+you+1);
    ll all = partition(zuo, you, b);
    ll r = partition(0, v.size() - 1, v);
    if (r % 2 == 0)
    {
        min = 0;
    }
    else
    {
        min = 2;
    }
    if(all%2==0)
    {
        if((right^1)>right)
        {
            max=right^1;
        }
        else
        {
            max=right;
        }
    }
    else
    {
        right=right^2;
        if((right^1)>right)
        {   
            max=right^1;
        }
        else
        {
            max=right;
        }
    }
    cout<<min<<" "<<max<<'\n';
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
}

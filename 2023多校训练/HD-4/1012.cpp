#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](pair<int, int> p1, pair<int, int> p2)
         { return (p1.first + p1.second) > (p2.first + p2.second); });
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        if(i % 2) sumB += arr[i].second;
        else sumA += arr[i].first;
    }
    cout<<sumA - sumB<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
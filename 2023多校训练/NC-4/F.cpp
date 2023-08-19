#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e6 + 5;
vector<pair<int,int>> arr(N); // index - potential

bool cmp(pair<int, int> p1, pair<int, int>p2){
    return p1.first < p2.first;
}

    int main()
{
    int n; cin>>n;
    for (int i = 1; i <= n; i++) 
    {
        arr[i].second = i;
        cin>>arr[i].first;
    }
    auto l = arr.begin() + 1;
    auto r = arr.begin() + n + 1;
    sort(l, r);
    if((r - l) <= 2)
    {
        cout<<l->second<<'\n';
        return 0;
    }
    
    while (r - l > 2)
    {
        double avg = 1.0 * (l->first + (r - 1)->first) / 2;
        pair<int,int> tmp{(int)ceill(avg),0};
        auto mid = lower_bound(l, r,tmp, cmp);
        int rc = r - mid,lc = mid - l;
        if (mid->first == avg)
            lc++,rc--;
        // cout << "mid: " << mid - l << " lc : " << lc << " rc : " << rc << '\n';
        if(lc < rc) l++;
        else r--;
    }
    cout<<l->second<<'\n';
}
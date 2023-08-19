#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    vector<int> pos;
    int cnt[5] = {0};
    int ans = INT32_MAX;
    int l = 0;
    for(int i = 0; i < n;i++) {
        bool lr = 0;
        bool k4 = 0;
        cin>>arr[i];
        cnt[arr[i]]++;
        while (cnt[1] && cnt[2] && cnt[3] && cnt[4] == k){
            ans = min(ans,i - l + 1);
            cnt[arr[l]]--;
            l++; lr = 1;
        }
        if (lr && l) {
            l--;
            cnt[arr[l]]++;
            lr = 0;
        }
        while(cnt[4] > k){
            cnt[arr[l]]--;
            l++; k4 = 1;
        }
        while (k4 && cnt[1] && cnt[2] && cnt[3] && cnt[4] == k)
        {
            ans = min(ans, i - l + 1);
            cnt[arr[l]]--;
            l++;
            lr = 1;
        }
        if (lr && l){
            l--;
            cnt[arr[l]]++;
        }
    }
    cout << ans << endl;
    return 0;
}
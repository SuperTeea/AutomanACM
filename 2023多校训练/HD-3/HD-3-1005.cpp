#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 3005;
int a[N];
int dp[N][N];
int n;
int cnt = 1;
bool repe[N];

void setdp(){

    for (int i = 1; i <= cnt; i++){
        dp[1][i] = i;
        dp[2][i] = i * (i + 1) / 2;
    }

    for (int i = 3; i <= cnt; i++){
        if (repe1) 
            dp[i][1] = dp[i-1][cnt];
        else 
            dp[i][1] = dp[i - 1][cnt - 1] - 1;

        for (int j = 2; j <= cnt; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][cnt-j+1];
        }
    }
}

void output(){
    cout << dp[1][cnt] << endl;
    if (repe1)
        cout << dp[2][cnt] << endl;
    else
        cout << dp[2][cnt] - 1 << endl;
    for (int i = 3; i <= cnt; i++){
        cout << dp[i][cnt] << endl;
    }

}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cnt = 1;
    for (int i = 1; i < n; i++){
        if (a[i] != a[i-1]) cnt++;
    }
    cout << "++" << cnt << endl;
    if (a[0] == a[1]) repe[1] = 1;

    setdp();
    
    output();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
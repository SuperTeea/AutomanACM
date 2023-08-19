#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<ll> a(n + 1),odd(n + 1),even(n + 1),ont(n + 1),ent(n + 1);
    a[0] = 0; odd[0] = 0; even[0] = 0; ont[0] = 0; ent[0] = 0;
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] % 2){
            cnt++;
            odd[i] = odd[i-1] + 1;
            even[i] = even[i-1];
            if (cnt % 2){
                ont[i] = ont[i-1] + 1;
            }
            else
                ont[i] = ont[i - 1] - 1;
            ent[i] = ent[i-1];
        }
        else{
            odd[i] = odd[i-1];
            even[i] = even[i-1] + 1;
            ont[i] = ont[i-1];
            cnt = 0;
            if (ont[i] % 2) {
                ent[i] = ent[i-1] + 1;
            }
            else
                ent[i] = ent[i - 1];
        }
    }
    
    for(int i = 0; i < q; i++){
        int l,r,k;
        cin >> l >> r >> k;
        int so = odd[r] - odd[l];
        int se = even[r] - even[l];
        if (a[l] % 2){
            so++;
        }
        else se++;
        if (so % 2)
            cout << "NO\n";
        else if (so / 2 + se >= k){
            int s = so / 2 + se;
            int ee = ent[r] - ent[l];
            if (a[l] % 2) ee++;
            if (ont[r]%2 == 0){
                s -= ee;
            }
            else s -= (se - ee);
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
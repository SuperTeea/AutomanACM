#include <iostream>
#include <string>
using namespace std;

void solve(){
    int n;
    string st;
    cin >> n >> st;
    string s = st;
    int len = st.size();
    for (int i = 0; i < n; i++){
        s += '1';
        if (s.substr(i + 1, len) == st){
            s.pop_back();
            s += '0';
        }
    }
    s += st;
    bool fail  = 0;
    for (int i = 1; i < len; i++){
        if (s.substr(n + i, len) == st){
            if (n + i >= len){
                if (s[n + i] == '1')
                    s[n + i] = '0';
                else
                    s[n + i] = '1';
                if (s.substr(n + i - len + 1, len) == st){
                    fail = 1;
                    break;
                }
            }
            else{
                bool ok = 0;
                for (int j = 0; j < n; j++){
                    if (s[len + j] == '1')
                        s[len + j] = '0';
                    else
                        s[len + j] = '1';

                    if (s.substr(j + 1, len) == st){
                        if (s[len + j] == '1')
                            s[len + j] = '0';
                        else
                            s[len + j] = '1';
                    }
                    else{
                        ok = 1;
                        break;
                    }
                }
                if (!ok){
                    fail = 1;
                    break;
                }
            }
        }
    }
    if (fail){
        cout << -1 << endl;
        return;
    }
    s = s.substr(len,n);
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
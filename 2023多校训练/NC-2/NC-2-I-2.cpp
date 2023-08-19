#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int X;
char refArro[4]{'o', 'o', 'x', 'x'};
char refArrx[4]{'x', 'x', 'o', 'o'};
char refArrR[4]{'x', 'o', 'x', 'o'};
char refArr1[2]{'x', 'o'};
char *refArr;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (m <= 4 || n <= 4)
    {
        for (int i = 0; i < n; i++)
        {
            int base = (i);
            for (int j = 0; j < m; j++)
            {
                cout << refArrR[(j + base) % 2];
            }
            if (i < n - 1) cout << '\n';
        }
        return;
    }

    refArr = refArrx;

    if (m % 2 == 1 && n % 2 == 0){
        for (int i = 0; i < n; i++){
            int base = i % 2;
            for (int j = 0; j < m - 1; j++){
                cout << refArrx[(base * 2 + j) % 4];
            }
            cout << refArr1[(((m - 1) / 2) % 2 + i) % 2] ;
            if (i < n-1) cout << endl;
        }
    }
    else if (m % 2 == 1 && n % 2 == 1)
    {
        for (int i = 0; i < n-1; i++)
        {
            int base = i % 2;
            for (int j = 0; j < m - 1; j++)
            {
                cout << refArrx[(base * 2 + j) % 4];
            }
            cout << refArr1[(((m - 1) / 2) % 2 + i) % 2] << endl;
        }
        for (int i = 0; i < m; i++){ //最后一行
            cout << refArr1[i % 2];
        }
    }
    else if (m % 2 == 0 && n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            int base = i % 2;
            for (int j = 0; j < m; j++)
            {
                cout << refArrx[(base * 2 + j) % 4];
            }
            //cout << refArr1[(((m - 1) / 2) % 2 + i) % 2];
            if (i < n - 1)
                cout << endl;
        }
    }
    else if (m % 2 == 0 && n % 2 == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int base = i % 2;
            for (int j = 0; j < m; j++)
            {
                cout << refArrx[(base * 2 + j) % 4];
            }
            // cout << refArr1[(((m - 1) / 2) % 2 + i) % 2];
            cout << endl;
        }
        for (int i = 0; i < m; i++)
        { // 最后一行
            cout << refArr1[i % 2];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
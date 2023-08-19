#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int X;
char refArro[4]{'o', 'o', 'x', 'x'};
char refArrx[4]{'x', 'x', 'o', 'o'};
char refArrR[4]{'x', 'o', 'x', 'o'};
char * refArr;
void solve()
{
    int n,m;
    cin>>n>>m;
    if(m <= 4 || n <= 4)
    {
        for (int i = 0; i < n; i++)
        {
            int base = (i);
            for (int j = 0; j < m; j++)
            {
                cout << refArrR[(j + base) % 2];
            }
            cout << '\n';
        }
        return;
    }

        refArr = refArrx;

    for (int i = 0; i < n; i++)
    {
        int base = (i * 2) % 4;
        for (int j = 0; j < m - 2; j++)
        {
            cout<<refArr[(j + base) % 4];
        }
        for (int j = 0; j < 2; j++)
        {
            if((i + j) % 2)
                cout<<'x';
            else
                cout<<'o';
        }


        cout<<'\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout<<"\n";
    }
}
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
char arr[55][55];
void solve()
{
    int n,Z;
    cin>>n>>Z;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }

    bool hasDiff = false;
    char c = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if(arr[i][j] != c)
            {
                hasDiff = true;
                break;
            }
        if(hasDiff) break;
    }


    if(Z == 100)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout<<arr[i][j];
            cout<<'\n';
        }

    else if(Z == 200)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j];
                cout << arr[i][j];
            }
            cout << '\n';
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j];
                cout << arr[i][j];
            }
            cout << '\n';
        }
    }
    else if(Z == 125 || Z == 175)
    {
        int len = n * Z;
        if(len % 100 == 0)
        {
            bool canZoom = false;
            vector<vector<char> > output;
            len /= 100;
            int it = n / 4;
            for (int out1 = 0; out1 < it; out1++)
            {
                output.emplace_back();
                for (int out2 = 0; out2 < it; out2++)
                {
                    char standard = arr[out1 * 4][out2 * 4];
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if(standard != arr[out1 * 4 + i][out2 * 4 + j])
                            {
                                cout<<"error\n";
                                return;
                            }
                        }
                    }
                    output[out1].push_back(standard);
                }
            }
            int zoom = Z / 25;
            for (int ii = 0; ii < it; ii++)
            {
                for (int i = 0; i < zoom; i++){
                    for (int jj = 0; jj < it; jj++)
                    {
                        for (int j = 0; j < zoom; j++){
                            cout << output[ii][jj];
                        }
                    }
                    cout << '\n';
                }
                
                
            }
            
            
            
        }
        else
            cout<<"error\n";
    }
    else if(Z == 150)
    {
        int len = n * Z;
        if (len % 100 == 0)
        {
            bool canZoom = false;
            vector<vector<char>> output;
            len /= 100;
            int it = n / 2;
            for (int out1 = 0; out1 < it; out1++)
            {
                output.emplace_back();
                for (int out2 = 0; out2 < it; out2++)
                {
                    char standard = arr[out1 * 2][out2 * 2];
                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            if (standard != arr[out1 * 2 + i][out2 * 2 + j])
                            {
                                cout << "error\n";
                                return;
                            }
                        }
                    }
                    output[out1].push_back(standard);
                }
            }
            int zoom = Z / 50;
            for (int ii = 0; ii < it; ii++)
            {
                for (int i = 0; i < zoom; i++)
                {
                    for (int jj = 0; jj < it; jj++)
                    {
                        for (int j = 0; j < zoom; j++)
                        {
                            cout << output[ii][jj];
                        }
                    }
                    cout << '\n';
                }
            }
        }
        else
            cout << "error\n";
    }

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
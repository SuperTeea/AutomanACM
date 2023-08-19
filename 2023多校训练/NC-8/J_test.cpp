#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int test_time = 10;

bool prime(int a)
{
    if (a <= 2)
        return 0;
    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

bool verify(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int a = v[i] + v[i - 1];
        int b = abs(v[i] - v[i - 1]);
        if(!prime(a) && !prime(b)) return false;
    }
    return true;
}

int main()
{
    int n,T = 6;
    cin>>n;
    vector<int> v(n);
    // int cnt = 0;
    for (int i = 0; i < n; i++) v[i] = i + 1;
    do if(verify(v)) 
    {
        if(!(T--))break;
         for (auto &&i : v) cout<<i<<' '; cout<<'\n' ;
        //  cnt++;
    } while (next_permutation(v.begin() + 1, v.end()));
    // cout<<cnt;
}
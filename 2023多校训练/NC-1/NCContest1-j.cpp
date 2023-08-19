#include <iostream>
using namespace std;
const int MO = 998244353;
using ll = long long;
int pow1(int a,int b,int p = MO)
{
    int ans = 1 % p;
    for(;b;b>>= 1)
    {
        if(b & 1) ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    int i = 1;
    long long limt = 1;
    long long possibX = 1;
    long long possibY = 1;
    while(limt <= n)
    {
        i++;
        limt = limt * 2 + 1;
    }
    int l = limt - n;
    long long ppX = pow1(2,i-1) - 1;
    long long ppY = ppX + 1;
    possibX *= pow1(ppX,l);
    possibX %= MO;
    possibY *= pow1(ppY,l);
    possibY %= MO;
    
    while(limt <= n + m)
    {
        i++;
        limt = limt * 2 + 1;
        l = (limt + 1) / 2;
        ppX = pow1(2,i-1) - 1;
        ppY = ppX + 1;
    possibX *= pow1(ppX,l);
    possibX %= MO;
    possibY *= pow1(ppY,l);
    possibY %= MO;

    }
    
    l = n + m - limt;
    ppX = pow1(2,i-1) - 1;
    ppY = ppX + 1;
    possibX *= pow1(ppX,l);
    possibX %= MO;
    possibY *= pow1(ppY,l);
    possibY %= MO;
    
//     cout<<possibX<<' '<<possibY;
    
    while(true)
    {
        if(!(possibX % possibY)) break;
        possibX += 998244353;
    }
    cout<<possibX / possibY;
}
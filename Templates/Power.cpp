#include <iostream>

int qpower(int a, int b, int p = 1000000007)
{
    int ans = 1 % p;
    while (b)
    {
        if(b & 1) ans = (long long) ans * a % p;
        a = (long long) a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a,n,p;
    std::cin>>a>>n>>p;
    std::cout<<qpower(a,n,p);
}
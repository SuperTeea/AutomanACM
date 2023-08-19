#include <iostream>
#include <cstdio>
using namespace std;
const int T = 100000;
int main()
{
    long long sum = 0, cnt = 0;
    int n;cin>>n;
    for (int i = 1; i <= T; i++)
        for (int x = 1; x <= n; x++)
        {
            cnt++;
            int l = 1, r = n;
            int times = 0;
            bool done = false;
            while (l != r)
            {
                times++;
                int guess = -1;
                guess = (rand() % n) + 1;

                if (guess == x)
                    break;
                else if (guess < x)
                {
                    l = max(guess + 1,l);
                }
                else
                {
                    r = min(guess - 1,r);
                }
                // if(l == x - 1 && r == x + 1) break;
            }
            sum += times;
        }
    cout<<(long double) sum / cnt;
}
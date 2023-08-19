#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        string A;
        cin>>A;
        int score = 0;
        for(int i=0;i<A.size()-1;i++)
        {   
            if(A[i]==A[i+1])
            {
                score++;
            }
        }
        cout<<score<<endl;
    }
}
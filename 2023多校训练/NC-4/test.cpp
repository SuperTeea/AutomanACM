#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int f[5][20];
    memset(f[0], 1, sizeof(f[0]));
    for (int i = 0; i < 20; i++){
        cout << f[0][i] << '\n';
    }
}
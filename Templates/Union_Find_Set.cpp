#include<vector>
#include <numeric>

// 从 0 开始
class Ufs
{
public:
    Ufs(int n);
    void merge(int x, int y);
    int find(int x);
private:
    std::vector<int> v;
};

Ufs::Ufs(int n) :
    v(n)
{
    std::iota(v.begin(),v.end(),0);
}

int Ufs::find(int x)
{
    if(v[x] == x) return x;
    else return v[x] = find(v[x]);
}

void Ufs::merge(int x,int y)
{
    v[find(x)] = find(y);
}
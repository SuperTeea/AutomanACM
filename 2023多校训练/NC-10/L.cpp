#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool strickly_lesser(array<int, 4> &a1, array<int, 4> &a2)
{
    if (a1[0] < a2[0] && a1[1] < a2[1] && a1[2] < a2[2])
        return true;
    else{
        
    }
    return false;
}

bool strickly_larger(array<int, 4> &a1, array<int, 4> &a2)
{
    if (a1[0] > a2[0] && a1[1] > a2[1] && a1[2] > a2[2])
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<array<int, 4>> v(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][3] = i;
    }
    if ((v[0][0] < v[1][0] && v[0][1] < v[1][1] && v[0][2] < v[1][2]) ||
        (v[0][0] > v[1][0] && v[0][1] > v[1][1] && v[0][2] > v[1][2]))
    {
        cout << "-1\n";
        return 0;
    }

    int cnt = 0;
    sort(v.begin(), v.end(),strickly_lesser);
    ans.push_back(make_pair(0, cnt));
    for (int i = 1; i < n; i++)
    {
        if (strickly_lesser(v[i - 1], v[i]))
            cnt++;
        ans.push_back(make_pair(v[i][3], cnt));
    }
    if (cnt > 255)
    {
        cout << "-1\n";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (auto &&p : ans)
    {
        cout << p.second << '\n';
    }
}
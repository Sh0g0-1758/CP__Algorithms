#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> unit;
vector<int> ans;
void riffle(vector<int> a, vector<int> &b)
{
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        x.push_back(a[b[i]]);
    }
    b.clear();
    for (int i : x)
    {
        b.push_back(i);
    }
}
void exp(int p)
{
    if (p == 0)
        return;
    exp(p / 2);
    riffle(ans, ans);
    if (p % 2)
    {
        riffle(unit, ans);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;
        unit.clear();
        ans.clear();
        for (int i = 0; i < n / 2; i++)
            unit.push_back(i * 2);
        for (int i = n / 2; i < n; i++)
            unit.push_back(1 + (i - n / 2) * 2);
        for (int i = 0; i < n; i++)
            ans.push_back(i);
        exp(k);
        for (int i = 0; i < n; i++)
            cout << (ans[i] + 1) << " ";
        cout << endl;
    }
}
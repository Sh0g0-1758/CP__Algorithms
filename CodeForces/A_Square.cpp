#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a,b,c,d,e,f,g,h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        cout << min((a-c)*(a-c) + (b-d)*(b-d), (a-e)*(a-e) + (b-f)*(b-f)) << endl;
    }
}
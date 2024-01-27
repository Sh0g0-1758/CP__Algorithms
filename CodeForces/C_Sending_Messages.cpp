#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n,f,a,b;
        cin >> n >> f >> a >> b;
        vector<ll> mess;
        mess.push_back(0);
        for(int i = 0; i < n;i++) {
            ll mem;
            cin >> mem;
            mess.push_back(mem);
        }
        ll t_sum = 0;
        for(int i = 0; i < mess.size() - 1;i++) {
            if((a * (mess[i+1] - mess[i])) < b) {
                t_sum += a * (mess[i+1] - mess[i]);
            } else {
                t_sum += b;
            }
        }
        if(t_sum < f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
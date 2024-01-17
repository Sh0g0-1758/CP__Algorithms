#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int t = 1; t <= n; t++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c % __gcd(a, b) == 0) cout << "Case " << t << ": Yes\n";
        else cout << "Case " << t << ": No\n";
    }
}
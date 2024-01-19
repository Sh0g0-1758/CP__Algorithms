#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int a,b;
	    cin >> a >> b;
	    if(__gcd(a,b) == 1) {
	        cout << a * b - a - b + 1 << endl;
	    } else {
	        cout << -1 << endl;
	    }
	}
	return 0;
}

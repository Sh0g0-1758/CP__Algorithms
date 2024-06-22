//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here

        int rem_low = l % 4;
        int low = l / 4;
        int rem_high = (4 - (r % 4))%4;
        int high = (r / 4) + 1;
        int ans = 0;

        for(int i = 4 * low; i < l;i++) {
            ans = ans ^ i;
        }
        
        for(int i = (high * 4) - 1; i > r;i--) {
            ans = ans ^ i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends
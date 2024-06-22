//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    long long ans = 0;
    
    void merge(long long temp[], int low, int mid, int high) {
        
        vector<int> left;
        for(int i = low; i <= mid;i++) {
            left.push_back(temp[i]);
        }
        
        vector<int> right;
        for(int i = mid + 1;i <= high;i++) {
            right.push_back(temp[i]);
        }
        
        int ind1 = 0;
        int ind2 = 0;
        int ind3 = low;
        
        while(ind1 < left.size() and ind2 < right.size()) {
            if(left[ind1] <= right[ind2]) {
                temp[ind3] = left[ind1];
                ind1++;
            } else {
                temp[ind3] = right[ind2];
                ind2++;
                ans+= (left.size() - ind1);
            }
            ind3++;
        }
        while(ind1 < left.size()) {
            temp[ind3] = left[ind1];
            ind1++;
            ind3++;
        }
        while(ind2 < right.size()) {
            temp[ind3] = right[ind2];
            ind2++;
            ind3++;
        }
    }
    
    void merge_op(long long temp[], int l, int r) {
        if (l < r) {
            long long mid = l + (r - l) / 2;
            merge_op(temp,l,mid);
            merge_op(temp,mid+1,r);
            merge(temp,l,mid,r);
        }
    }
    
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        ans = 0;
        merge_op(arr,0,n-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        int prelim_ans = 0;
        for(int i = 0; i < N;i++) {
            prelim_ans = prelim_ans ^ Arr[i];
        }
        int rightmostsetbit = prelim_ans & ~(prelim_ans - 1);
        int x = 0;
        int y = 0;
        for(int i = 0; i < N;i++) {
            if(rightmostsetbit & Arr[i]) {
                x = x ^ Arr[i];
            } else {
                y = y ^ Arr[i];
            }
        }
        vector<long long int> res;
        if(y > x) swap(x,y);
        res.push_back(x);
        res.push_back(y);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
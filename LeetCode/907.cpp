class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> stck;
        vector<int> minPrev(n,-1), minNext(n,n);

        for(int i = 0; i < n;i++) {
            while(!stck.empty() and nums[stck.top()] >= nums[i]) stck.pop();
            if(!stck.empty()) minPrev[i] = stck.top();
            stck.push(i);
        }

        while(!stck.empty()) stck.pop();

        for(int i = n -1; i >= 0;i--) {
            while(!stck.empty() and nums[stck.top()] > nums[i]) stck.pop();
            if(!stck.empty()) minNext[i] = stck.top();
            stck.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n;i++) {
            long long minPrevDistance = i - minPrev[i];
            long long minNextDistance = minNext[i] - i;
            ans = (ans + (long long)(minPrevDistance) * (long long)(minNextDistance) * (long long)nums[i])%mod;
        }
        return ans;
    }
};
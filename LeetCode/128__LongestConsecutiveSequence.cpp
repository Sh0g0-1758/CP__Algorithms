class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int u = *max_element(nums.begin(),nums.end());
        int l = *min_element(nums.begin(),nums.end());
        int arr[u - l + 1];
        for(auto it : nums) {
            arr[it - l] = 1;
        }
        int ans = INT_MIN;
        int counter = 0;
        for(int i = 0; i < u - l + 1;i++) {
            if(arr[i] == 1) {
                counter++;
                ans = max(ans,counter);
            } else {
                counter = 0;
            }
        }
        return ans;
    }
};

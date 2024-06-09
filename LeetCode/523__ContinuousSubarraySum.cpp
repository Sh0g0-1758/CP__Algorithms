class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 1; i < nums.size();i++) {
            nums[i] = nums[i] + nums[i-1];
        }
        for(int i = 0; i < nums.size();i++) {
            nums[i] = nums[i] % k;
        }
        map<int,int> mp;
        mp[nums[0]] = 0;
        bool ans = false;
        for(int i = 1; i < nums.size();i++) {
            if(nums[i] == 0) {
                ans = true;
                break;
            }
            if (mp.find(nums[i]) != mp.end()) {
                if(i - mp[nums[i]] > 1) {
                    ans = true;
                    break;
                }
            } else {
                mp[nums[i]] = i;
            }
        }
        if(ans) {
            return true;
        }else{
            return false;
        }
    }
};
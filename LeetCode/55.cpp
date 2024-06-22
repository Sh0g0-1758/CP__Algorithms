class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for(int i = 0; i < nums.size();i++) {
            if(i <= max_reach) {
                max_reach = max(max_reach, i + nums[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

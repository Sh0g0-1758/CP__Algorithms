class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto a: nums) {
            for(auto b : nums) {
                mp[a & b]++;
            }
        }
        for(auto a : nums) {
            for(auto b : mp) {
                if((a & b.first) == 0) {
                    ans+=b.second;
                }
            }
        }
        return ans;
    }
};

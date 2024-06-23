class Solution {
public:

    void helper(set<vector<int>>& res, vector<int>&nums,vector<int> temp,int ind, int n) {
        if(ind == n) {
            if(temp.size() > 1) sort(temp.begin(),temp.end());
            res.insert(temp);
            return;
        }
        helper(res,nums,temp,ind+1,n);
        temp.push_back(nums[ind]);
        helper(res,nums,temp,ind+1,n);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        helper(res,nums,temp,0,nums.size());
        vector<vector<int>> ans;
        for(auto it : res) {
            ans.push_back(it);
        }
        return ans;
    }
};
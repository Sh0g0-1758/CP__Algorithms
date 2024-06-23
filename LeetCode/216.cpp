class Solution {
public:

    void helper(vector<vector<int>>& res, int curr, int k, int n, vector<int> temp) {
        // Base Cases
        if(k == 0) {
            if(n == 0) res.push_back(temp);
            return;
        }
        if(n < 0 or k < 0) return;
        if(curr == 10) return;

        // Not Take
        helper(res,curr+1,k,n,temp);

        // Take
        temp.push_back(curr);
        helper(res,curr+1,k - 1,n-curr,temp);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,1,k,n, temp);
        return res;
    }
};

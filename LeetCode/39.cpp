class Solution {
public:

    void help(set<vector<int>>& res, vector<int>& candidates, int target, vector<int> hel) {
        if(target < 0) {
            return;
        }

        if(target == 0) {
            sort(hel.begin(),hel.end());
            res.insert(hel);
            return;
        }

        // Main Logic : 
        // Same ELement reuse.  Candidates iterate for every element, main har element ko pivot, main har ko base bana raha hoon and then main help call kar rha hoon.
        // [] -> [2,3,6,7]
        // [2] -> [2,3,6,7]
        // [3] -> [2,3,6,7]
        // [6] -> [2,3,6,7]
        // [7]
        for(int i = 0; i < candidates.size();i++) {
            hel.push_back(candidates[i]);
            help(res,candidates,target - candidates[i],hel);
            hel.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> hel;
        // [2,2,3] , [2,3,2] -> [2,2,3]
        set<vector<int>> res;
        help(res,candidates,target, hel);
        vector<vector<int>> ans;
        for(auto it : res) {
            ans.push_back(it);
        }
        return ans;
    }
};
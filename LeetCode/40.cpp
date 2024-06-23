class Solution {
public:

    void help(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int> hel, int indx) {
        if(target == 0) {
            res.push_back(hel);
            return;
        }

        for(int i = indx; i < candidates.size();i++) {
            if (i > indx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            hel.push_back(candidates[i]);
            help(res,candidates,target - candidates[i],hel,i+1);
            hel.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> hel;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        help(res,candidates,target, hel,0);
        return res;
    }
};

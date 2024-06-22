class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> comb;
        for(int i = 0; i < profit.size();i++) {
            comb.push_back({profit[i],difficulty[i]});
        }
        sort(comb.begin(),comb.end());
        reverse(comb.begin(),comb.end());
        sort(worker.begin(),worker.end());
        reverse(worker.begin(),worker.end());
        int ind_comb = 0;
        int ind_worker = 0;
        int ans = 0;
        while(ind_comb < comb.size() and ind_worker < worker.size()) {
            if(comb[ind_comb].second > worker[ind_worker]) {
                ind_comb++;
            } else {
                ans+=comb[ind_comb].first;
                ind_worker++;
            }
        }
        return ans;
    }
};
class Solution {
public:

    bool okay(vector<int>& weights, int days, int mid) {
        int cnt_days = 1;
        int cnt_mid = 0;
        for(int i = 0; i < weights.size();i++) {
            if(cnt_mid + weights[i] <= mid) {
                cnt_mid += weights[i];
            } else {
                cnt_days++;
                cnt_mid = weights[i];
            }
        }
        if(cnt_days <= days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (okay(weights,days,mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

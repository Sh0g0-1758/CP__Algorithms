class Solution {
public:
    int helper(vector<int>& freq) {
        int max_freq = INT_MIN;
        int min_freq = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] > max_freq) {
                    max_freq = freq[i];
                }
                if (freq[i] < min_freq) {
                    min_freq = freq[i];
                }
            }
        }

        return max_freq - min_freq;
    }

    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                ans += helper(freq);
            }
        }
        return ans;
    }
};

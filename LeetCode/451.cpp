class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(100, 0);
        for (auto it : s) {
            freq[it - '0']++;
        }
        vector<pair<int,int>> res;
        for(int i = 0; i < freq.size();i++) {
            if(freq[i] != 0) {
                res.push_back({freq[i],i});
            }
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        string ans = "";
        for(auto it : res) {
            if(it.first == 0) break;
            while(it.first--) {
                ans+=((char)(it.second + '0'));
            }
        }t-
// Long Long -> 64 bits
// Int -> 32 bits
// Char -> 8 bits
// Int + Char -> Int
// Long long + Int -> Long Long
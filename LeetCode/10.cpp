class Solution {
public:

    bool check(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        if(i >= s.size() and j >= p.size()) return dp[i][j] = true;
        if(j >= p.size()) return dp[i][j] = false;

        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');

        if (j + 1 < p.size() and p[j+1] == '*') return dp[i][j] = (match and check(i+1,j,s,p,dp)) or check(i,j+2,s,p,dp);

        if (match) return dp[i][j] = check(i+1,j+1,s,p,dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 10,vector<int>(p.size() + 10,-1));
        return check(0,0,s,p,dp);
    }
};

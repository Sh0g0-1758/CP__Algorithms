class Solution {
public:
    bool helper(int start, int end, string s, map<string,bool>& mp, vector<int> &vis) {
        if (start > end) return true;
        if (vis[start] != -1) return vis[start];
        string temp = "";
        bool flag = false;
        for(int i = start; i <= end;i++) {
            temp.push_back(s[i]);
            if (mp.find(temp) != mp.end()) {
                flag = helper(i+1,end,s,mp,vis);
                if(flag) break;
            }
        }
        return vis[start] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> mp;
        for(auto it : wordDict) {
            mp[it] = true;
        }
        vector<int> vis(s.size()+3,-1);
        return helper(0,s.size() - 1,s,mp,vis);
    }
};

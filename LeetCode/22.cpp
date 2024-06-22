class Solution {
public:
    vector<string> result;
    void help(string &s, int open, int close, int n) {
        // If the number of open and close are both equal to n
        if(open == close and open == n) {
            result.push_back(s);
        }
        // if close < open, then you can insert a close bracket
        if(close < open and close < n) {
            s.push_back(')');
            help(s,open,close+1,n);
            s.pop_back();
        }
        // If open < n, we can insert open brackets, so insert the open bracket
        if(open < n) {
            s.push_back('(');
            help(s,open+1,close,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        help(s,0,0,n);
        return result;
    }
};
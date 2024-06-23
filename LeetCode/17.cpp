class Solution {
public:

    void helper(vector<string>& res,int ind, string& digits, int n, string temp) {
        if(ind == n) {
            res.push_back(temp);
            return;
        }
        if(digits[ind] == '9' or digits[ind] == '7') {
            char start_char = 'a';
            if (digits[ind] == '7') start_char = 'p';
            if (digits[ind] == '9') start_char = 'w';
            for(int i = 0; i < 4; i++) {
                temp.push_back((char)(start_char + i));
                helper(res,ind+1,digits,n,temp);
                temp.pop_back();
            }
        } else {
            char start_char = 'a';
            if (digits[ind] == '2') start_char = 'a';
            if (digits[ind] == '3') start_char = 'd';
            if (digits[ind] == '4') start_char = 'g';
            if (digits[ind] == '5') start_char = 'j';
            if (digits[ind] == '6') start_char = 'm';
            if (digits[ind] == '8') start_char = 't';
            for(int i = 0; i < 3;i++) {
                temp.push_back((char)(start_char + i));
                helper(res,ind+1,digits,n,temp);
                temp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "") return res;
        string temp = "";
        helper(res,0,digits,digits.size(), temp);
        return res;
    }
};

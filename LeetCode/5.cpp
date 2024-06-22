class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string ans_string = "";
        int n = s.length();
        for(int i = 0; i < n;i++) {
            // These are odd length
            // I am centering my palindrome center at i
            // Left = i - 1
            // Right = i + 1
            int cnt = 1;
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right]) {
                cnt+=2;
                left--;
                right++;
            }
            left++;right--;
            if (cnt > ans) {
                ans_string = s.substr(left, right - left + 1);
                ans = cnt;
            }
            // Even Palindromes
            cnt = 0;
            left = i;
            right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right]) {
                cnt+=2;
                left--;
                right++;
            }
            left++;right--;
            if (cnt > ans) {
                ans_string = s.substr(left,right-left+1);
                ans = cnt;
            }
        }
        return ans_string;
    }
};

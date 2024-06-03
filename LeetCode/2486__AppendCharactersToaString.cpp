class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ind2 = 0;
        int sl = s.size();
        int tl = t.size();
        for(int i = 0; i < sl && ind2 < tl;i++) {
            if(t[ind2] == s[i]) {
                ind2++;
            }
        }
        return tl - ind2;
    }
};
#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll left = 0;
        ll right = sqrt(c);
        while(left <= right) {
            ll temp = left * left + right * right;
            if(temp == c) {
                return true;
            } else if (temp < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};

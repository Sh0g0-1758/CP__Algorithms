class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stck;
        vector<int> prevMin(n, -1), nextMin(n, n);

        for(int i = 0; i < n; i++) {
            while(!stck.empty() and heights[stck.top()] >= heights[i]) stck.pop();
            if(!stck.empty()) prevMin[i] = stck.top();
            stck.push(i);
        }

        while(!stck.empty()) stck.pop();

        for(int i = n - 1; i >=0;i--) {
            while(!stck.empty() and heights[stck.top()] >= heights[i]) stck.pop();
            if(!stck.empty()) nextMin[i] = stck.top();
            stck.push(i);
        }

        int ans = INT_MIN;
        for(int i = 0; i < n;i++) {
            int leftDistance = i - prevMin[i] - 1;
            int rightDistance = nextMin[i] - i - 1;
            ans = max(ans, heights[i] * (leftDistance + rightDistance + 1));
        }
        return ans;
    }
};

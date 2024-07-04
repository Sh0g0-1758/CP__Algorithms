class Solution {
public:
    int trap(vector<int>& height) {
        queue<int> stock;
        int ans = 0;

        // Front Traversal
        for (auto it : height) {
            if(stock.empty()) stock.push(it);
            else {
                if(stock.front() <= it) {
                    int bar = stock.front();
                    stock.pop();
                    while(!stock.empty()) {
                        ans += bar - stock.front();
                        stock.pop();
                    }
                    stock.push(it);
                } else {
                    stock.push(it);
                }
            }
        }

        // Reverse Traversal
        stack<int> reverseStock;
        while(!stock.empty()) {
            reverseStock.push(stock.front());
            stock.pop();
        }

        while(!reverseStock.empty()) {
            int bar = reverseStock.top();
            reverseStock.pop();
            vector<int> store;
            while(!reverseStock.empty() and reverseStock.top() < bar) {
                store.push_back(reverseStock.top());
                reverseStock.pop();
            }
            for(auto it : store) {
                ans += bar - it;
            }
        }

        return ans;
    }
};
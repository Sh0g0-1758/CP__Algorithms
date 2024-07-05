class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        for(auto it : asteroids) {
            if(it > 0) ast.push(it);
            else {
                while(!ast.empty() and ast.top() < abs(it) and ast.top() > 0) {
                    ast.pop();
                }
                if(ast.empty()) ast.push(it);
                else{
                    if(ast.top() < 0) ast.push(it);
                    else if(ast.top() == abs(it)) {
                        ast.pop();
                    }
                }
            }
        }
        vector<int> res;
        while(!ast.empty()) {
            res.push_back(ast.top());
            ast.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
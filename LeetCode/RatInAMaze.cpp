//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string> &ans, string temp) {
        if(i < 0 or j < 0 or i == n or j == n) return;
        if(maze[i][j] == 0) return;
        if(i == n-1 and j == n-1) {ans.push_back(temp);return;}
        
        maze[i][j] = 0;
        
        temp.push_back('D');
        solve(i+1,j,maze,n,ans,temp);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1,j,maze,n,ans,temp);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i,j-1,maze,n,ans,temp);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i,j+1,maze,n,ans,temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp = "";
        solve(0,0,m,n,ans,temp);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
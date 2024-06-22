//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    long long atMostK (string s, int k) {
        // Variables with zero
        int i = 0, j = 0, cnt = 0;
        // Result variable
        long long res = 0;
        // Frequence array initialize to zero
        int m[26] = {0};
        
        // Iterate over all the string elements
        while (j < s.length()) {
            // Freq of character increase
            m[s[j] - 'a']++;
            // If the character is unique, then increase the count of unique characters
            if(m[s[j] - 'a'] == 1) cnt++;
            
            // If that count has become more than the threshold, then decrease cnt
            // J -- Upper Limit of Window
            // I -- Lower Limit of window
            // Jo string we have traversed, we will decrease it from the starting
            while(cnt > k) {
                m[s[i] - 'a']--;
                // If zero, then unique charcter count should decrease
                if (m[s[i] - 'a'] == 0) cnt--;
                i++;
            }
            // We are adding all the possible substrings that can arise from that length of the window
            // 1 2 3 4
            // 1 --> 1 (1)
            // 2 --> 3 (1 + 2)
            // 3 --> 6 (1 + 2 + 3)
            res += (j - i + 1);
            j++;
        }
        
        return res;
    }
    // atmost k --> k distinct and less than k distinct aap calculate kar lo. 
    // Atmost(k) - Atmost(k - 1) --> Exactly(K)
    long long int substrCount (string s, int k) {
    	//code here.
    	return atMostK (s,k) - atMostK (s, k - 1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
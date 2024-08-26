//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int wildCard(string pattern, string str) {
    int n = pattern.size();
    int m = str.size();

    // Create a 2D DP array initialized with 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: if both pattern and string are fully traversed, it's a match
    dp[n][m] = 1;

    // Iterate over the pattern and string in reverse order
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {

            // Case 1: Both pattern and string are fully traversed
            if (i == n && j == m) {
                dp[i][j] = 1;
            }
            // Case 2: Pattern is fully traversed, but string is not
            else if (i == n) {
                dp[i][j] = 0;
            }
            // Case 3: String is fully traversed, but pattern is not
            else if (j == m) {
                if (pattern[i] == '*') {
                    // '*' can match an empty sequence
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
            // Case 4: Compare characters of pattern and string
            else {
                if (pattern[i] == str[j]) {
                    // Characters match, move both pointers
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (pattern[i] == '?') {
                    // '?' matches any single character
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (pattern[i] == '*') {
                    // '*' can match an empty sequence or any sequence
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                } else {
                    // Characters do not match
                    dp[i][j] = 0;
                }
            }
        }
    }

    // Return the result for the entire strings
    return dp[0][0];
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
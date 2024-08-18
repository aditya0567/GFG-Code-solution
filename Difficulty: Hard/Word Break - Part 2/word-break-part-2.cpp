//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
           unordered_set<string> wordSet(dict.begin(), dict.end());
        int len = s.length();
        vector<vector<string>> dp(len + 1);
        dp[0] = {""};

        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end()) {
                    for (auto str : dp[j]) {
                        dp[i].push_back(str + (str.empty() ? "" : " ") + word);
                    }
                }
            }
        }
        return dp[len];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        if(find(B.begin() , B.end() , A)!=B.end())
      {
          return 1;
      }
      
      for(int i=0 ; i<A.size() ; i++)
      {
          if(find(B.begin() , B.end() , A.substr(0 , i))!=B.end()&&wordBreak(A.substr(i) , B))
          {
          return 1;
          }
      }
      return 0;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
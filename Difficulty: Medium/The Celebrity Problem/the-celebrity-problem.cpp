//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
     bool knowsnoone(vector<vector<int>> &mat, int i, int n)
    {
        for(int j=0;j<n;j++) if(mat[i][j]!=0) return false;
        return true;
    }
    
    bool allknowone(vector<vector<int>> &mat, int j, int m)
    {
        for(int i=0;i<m;i++) if(mat[i][j]!=1 && i!=j) return false;
        return true;
    }
    
    int celebrity(vector<vector<int> >& mat) {
        int n=mat[0].size();
        int m=mat.size();
        if(knowsnoone(mat,0,n) && allknowone(mat,0,m)) return 0;
        for(int j=0;j<n;j++)
            if(mat[0][j]==1)
                if(knowsnoone(mat,j,n) && allknowone(mat,j,m)) return j;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
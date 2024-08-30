//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    
    bool check(vector<vector<int>> v, int n, int row, int col) {
        // no need to check whole diagonal as we are filling from left to right
        // similarly no need to check colums (vertical)
        
        // horizontal
        for (int k = 0; k < col; k++) {
            if (v[row][k] == 1)
                return false;
        }
        
        // diagonals
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (v[i][j] == 1)
                return false;
        }
        
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (v[i][j] == 1)
                return false;
        }
        
        return true;
    }
    
    void solve(vector<vector<int>> v, int n, int col, vector<int> temp) {
        
        for (int i = 0; i < n; i++) {
            if (check(v, n, i, col)) {
                v[i][col] = 1;
                
                temp.push_back(i + 1);
                solve(v, n, col + 1, temp);
                
                v[i][col] = 0;
                temp.erase(temp.end() - 1);
            }
        }
        
        if (temp.size() == n) ans.push_back(temp);
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        if (n == 1)
            return {{1}};
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        vector<int> temp;
        
        solve(v, n, 0, temp);
        
        return ans;
    }
};











//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
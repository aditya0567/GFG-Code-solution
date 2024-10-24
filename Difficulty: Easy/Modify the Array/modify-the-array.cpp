//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
          int n = arr.size(), start = 0, i;
        vector<int> res(n);
        for( i=1; i<n; i++ )
            if( arr[i-1] ) {
                if( arr[i] == arr[i-1] ) {
                    res[start++] = 2 * arr[i-1];
                    i++;
                } else
                    res[start++] = arr[i-1];
            }
        if( i == n && arr[n-1] )
            res[start++] = arr[n-1];
        while( start < n )
            res[start++] = 0;
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    vector<int> visited(n+1, 0);  // To track visited elements
    visited[0] = 1;  // Marking 0 as visited because it's not a valid index

    // Find the duplicate
    for(int i = 0; i < n; i++){
        if(visited[arr[i]] == 0) {  // Check if the element is visited
            visited[arr[i]] = 1;
        }
        else if(visited[arr[i]] == 1) {  // If already visited, it's a duplicate
            ans.push_back(arr[i]);
        }
    }

    // Find the missing element
    for(int i = 1; i <= n; i++){  // Iterate from 1 to n to find the missing number
        if(visited[i] == 0){  // If an element is not visited, it's the missing one
            ans.push_back(i);
            break;
        }
    }

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
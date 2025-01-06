//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
           vector<int> ans(2,-1);
        int diff=INT_MAX;
        
        sort(arr.begin(),arr.end());
        int low=0;
        int up=arr.size()-1;
        
        while(low<up){
            int sum=arr[low]+arr[up];
            
            int cDiff=abs(target-sum);
            if(cDiff < diff){
                diff=cDiff;
                ans[0]=arr[low];
                ans[1]=arr[up];
                
                
            }
            
            
            
            if(sum<target)
                low++;
            else
                up--;
            
        }
        
        if(ans[0]==-1){
            vector<int> ans;
            return ans;
            
        }
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
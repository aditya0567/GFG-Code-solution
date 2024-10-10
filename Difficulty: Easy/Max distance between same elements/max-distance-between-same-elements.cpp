//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
         unordered_map<int,int>mp;
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]>0){
            // {cout<<"T"<<arr[i]<<" "<<mp[arr[i]]<<" ";
                ans=max(ans,i-mp[arr[i]]+1);
                continue;
            }
            mp[arr[i]]=i+1;
        }
        
        return ans;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
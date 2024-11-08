//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
         vector<int>ans;
        sort(arr.begin(),arr.end());
        
        int count1=0, count2=0;
        for(int i=0; i<arr.size(); i++){
            
            if(i%2==0){
            ans.push_back(arr[arr.size()-1-count1]);
            count1++;
            }
            
            else{
            ans.push_back(arr[count2]);
            count2++;
            }
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
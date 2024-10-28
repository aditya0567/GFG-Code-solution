//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> removeDuplicate(vector<int>& arr) 
    {
        vector<int> temp(101,0);
        int j = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(temp[arr[i]] == 0)
            {
                arr[j] = arr[i];
                j++;
                temp[arr[i]]++;
            }
        }
        
        while(j < arr.size())
            arr.pop_back();
            
        return arr;
        // code here
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
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
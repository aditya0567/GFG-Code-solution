//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
        if(arr.size()==1) return 1;
        if(arr.size()==2){
            if(arr[0] == 0) return 2;
            if(arr[1] == 0) return 1;
        }
        long long leftSum=0,rightSum=0;
        for(int i=1;i<arr.size();i++) rightSum+=arr[i];
        for(int i=1;i<arr.size();i++){
            leftSum+=arr[i-1];
            rightSum-=arr[i];
            if(leftSum==rightSum) return i+1;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends
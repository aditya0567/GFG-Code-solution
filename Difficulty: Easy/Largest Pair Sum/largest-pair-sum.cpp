//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
          int arrsize = arr.size();
        int answer1 = INT_MIN;
        int answer2 = INT_MIN;
        // Traverse the array >>
        for(int i = 0; i<arrsize; i++)
        {
            if(arr[i] > answer1)
            answer1 = arr[i];
        }
        for(int i = 0; i<arrsize; i++)
        {
            if(arr[i] == answer1)
            continue;
            else
            {
                if(arr[i]> answer2)
                answer2 = arr[i];
            }
        }
        return answer1+answer2;
    
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
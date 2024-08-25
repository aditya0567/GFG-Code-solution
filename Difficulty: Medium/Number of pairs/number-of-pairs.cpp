//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     double transformedValue(int x){
        return (double)x / log2(x);
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
    //   x^y > y^x
    //   y log x > x log y
    //   y / log y > x / log x
        int n = arr.size();
        int m = brr.size();
        vector<double> bin (m);
        for(int i = 0; i < m; i++){
            bin[i] = transformedValue(brr[i]);
        }
        sort(bin.begin(), bin.end());
        long long ans = 0LL;
        for(auto x : arr){
            double value = transformedValue(x);
            int left = 0, right = m - 1;
            int validPairs = 0;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(bin[mid] > value){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                    validPairs = mid + 1;
                }
            }
            ans += m - validPairs;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
		bool recreationalSpot(int arr[], int n){
		if (n < 3) return false;
        stack<pair<int, int>> st;
        int minLeft = INT_MAX;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] >= st.top().first) {
                st.pop();
            }
            if (!st.empty() && arr[i] < st.top().first && arr[i] > st.top().second) {
                return true;
            }
            st.push({arr[i], minLeft});
            minLeft = min(arr[i], minLeft);
        }
        return false;
        
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends
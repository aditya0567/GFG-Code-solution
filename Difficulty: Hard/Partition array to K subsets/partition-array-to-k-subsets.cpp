//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
            int total = accumulate(a, a+n, 0);
        int partition = total/k;
        if(partition*k != total) return false;
        sort(a, a+n);
        if(a[n-1] > partition) return false;
        
        priority_queue<int> pq;
        while(k--) pq.push(0);
        
        for(int i = n-1; i >= 0; i--){
            int x = pq.top(); pq.pop();
            pq.push(x-a[i]);
            if(-1*(x-a[i]) > partition) return false;
        }
        
        while(!pq.empty()){
            if(-pq.top() != partition) return false;
            pq.pop();
        }
        return true;
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
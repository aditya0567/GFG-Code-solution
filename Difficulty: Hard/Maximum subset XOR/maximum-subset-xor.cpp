//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
          if(N==0)return 0;

    // Initialize x to 0. This will keep track of the maximum XOR found so far.
    int x=0;

    // Enter an infinite loop, which will only break when the maximum element in the array becomes 0.
    while(1){
        // Find the maximum element in the array
        int y=*max_element(arr,arr+N);

        // If the maximum element is 0, it means all elements in the array have been reduced to 0.
        // So, return the maximum XOR found so far.
        if(y==0)return x;

        // Update x to be the maximum of x and x XOR y.
        // The XOR of x and y could potentially be a larger number than x.
        x=max(x,x^y);

        // Update each element in the array to be the minimum of the element and the element XOR y.
        // This step effectively removes the bit y from all elements in the array that have it.
        for(int i=0;i<N;i++){
            arr[i]=min(arr[i],arr[i]^y);
        }
    }

    // This line will never be reached because the function will return from inside the loop.
    // But it's here to avoid compiler warnings.
    return x;

    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends
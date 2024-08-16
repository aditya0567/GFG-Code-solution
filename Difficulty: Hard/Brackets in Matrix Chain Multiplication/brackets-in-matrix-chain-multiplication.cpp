//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
     int dp[101][101];
    string sp[101][101];
    int helper(int lo, int hi, int arr[]){
        if(lo==hi){
            sp[lo][hi]="A";
            sp[lo][hi][0]+=lo;
            return 0;
        }
        if(dp[lo][hi]!=-1) return dp[lo][hi];
        sp[lo][hi]="(";
        dp[lo][hi]=INT_MAX;
        for(int i=lo;i<hi;++i){
            dp[lo][hi]=min(dp[lo][hi],helper(lo,i,arr)+helper(i+1,hi,arr)+arr[lo]*arr[i+1]*arr[hi+1]);
        }
        for(int i=lo;i<hi;++i){
            if(dp[lo][hi]==helper(lo,i,arr)+helper(i+1,hi,arr)+arr[lo]*arr[i+1]*arr[hi+1]){
                sp[lo][hi]+=sp[lo][i];
                sp[lo][hi]+=sp[i+1][hi];
                break;
            }
        }
        sp[lo][hi]+=")";
        return dp[lo][hi];
    }
    string matrixChainOrder(int arr[], int n){
        // code here
        memset(dp,-1,sizeof(dp));
        helper(0,n-2,arr);
        // cout<<sp[0][n-2]<<" ";
        return sp[0][n-2];
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
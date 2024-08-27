//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bitCnt(int x){
        int cnt=0;
        while(x)
        {
            cnt+=x&1;
            x=x>>1;
        }
        return cnt;
    }
    
    vector<int> toBinary(int x){
        vector<int>ans;
        while(x){
            ans.push_back(x&1);
            x=x>>1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int toNum(vector<int>&ans){
        int x=0;
        for(int i=0;i<ans.size();i++){
            x=x*2+ans[i];
        }
        return x;
    }
    
    int minVal(int a, int b) {
        int cnt_a=bitCnt(a),cnt_b=bitCnt(b);
        
        if(cnt_a==cnt_b)
            return a;
        if(cnt_b<cnt_a){
            vector<int>ans=toBinary(a);
            int cnt=cnt_a-cnt_b;
            reverse(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                if(!cnt)
                    break;
                if(ans[i]==1)
                {
                    ans[i]=0;
                    cnt--;
                }
            }
            reverse(ans.begin(),ans.end());
            return toNum(ans);
        }
        vector<int>ans=toBinary(a);
        reverse(ans.begin(),ans.end());
        int cnt=cnt_b-cnt_a;
        for(int i=0;i<ans.size();i++){
            if(!cnt)
                break;
            if(ans[i]==0){
                cnt--;
                ans[i]=1;
            }
        }
        while(cnt){
            ans.push_back(1);
            cnt--;
        }
        reverse(ans.begin(),ans.end());
        return toNum(ans);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
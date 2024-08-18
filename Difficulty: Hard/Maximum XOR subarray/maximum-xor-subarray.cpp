//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



class trieNode
{
public:
    int freq;
    trieNode *left;
    trieNode *right;
    trieNode()
    {
        freq = 0;
        left = NULL;
        right = NULL;
    }
};
void insert(int n, trieNode *head)
{
    trieNode *cur = head;
    for (int i = 31; i >= 0; --i)
    {
        int bit = (n >> i) & 1;
        if (bit)
        {
            if (!cur->right)
            {
                cur->right = new trieNode();
            }
            cur = cur->right;
            cur->freq++;
        }
        else
        {
            if (!cur->left)
            {
                cur->left = new trieNode();
            }
            cur = cur->left;
            cur->freq++;
        }
    }
}

int findMaxXOR(int n, trieNode *head)
{
    trieNode *cur = head;
    int ans = 0;
    for (int j = 31; j >= 0; --j)
    {
        int bit = (n >> j) & 1;
        if (bit)
        {
            if (cur->left && cur->left->freq > 0)
            {
                ans += (1 << j);
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        else
        {
            if (cur->right && cur->right->freq > 0)
            {
                ans += (1 << j);
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
    }
    return ans;
}

class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[])
    {    
        trieNode *head = new trieNode();
        int pre = 0;
        int ans = 0;
        insert(0, head);
        for (int i = 0; i < n; ++i)
        {
            pre ^= arr[i];
            ans = max(ans, findMaxXOR(pre, head));
            insert(pre, head);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
       int ans=-1;
    
    bool isBST( Node * root, long long l, long long h)
    {
         if(root==NULL)
        {
            return true;
        }
        if(root->data >= h || root->data <= l)return false;
        else
        {
            return isBST(root->left,l,root->data) && isBST(root->right,root->data,h);
        }
    }
    
    pair<int,int> solve(Node* root,int target){
        if(root==NULL)return {0,0};

        pair<int,int> leftsum=solve(root->left,target);
        pair<int,int> rightsum=solve(root->right,target);


        int sum=leftsum.first+rightsum.first+root->data;
        int count=leftsum.second+rightsum.second+1;


        if(sum==target){
            if(isBST(root,LONG_MIN,LONG_MAX)){
                if(ans==-1)ans=count;
                else ans=min(count,ans);
            }
        }        return {sum,count};
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        
        if(root->left==NULL and root->right==NULL){
            if(root->data==target)return 1;
            else return -1;
        }


        solve(root,target);
        return ans;
    }


};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends
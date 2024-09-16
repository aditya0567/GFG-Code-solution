//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    bool solve(Node *root,string &s,int x)
    {
        // Base Case
      if(root==NULL) return false;
      if(root->data==x) return true;
       s.push_back('L');
       if(solve(root->left,s,x)) return true;
       s.pop_back();
       s.push_back('R');
       if(solve(root->right,s,x)) return true;
       s.pop_back();
       return false;
    }
    Node* findLCA(Node* root,int p,int q)
    {
        if(root==NULL) return NULL;
       if(root->data==p || root->data==q) return root;
       Node* LCA1 = findLCA(root->left,p,q);
       Node* LCA2 = findLCA(root->right,p,q);
       if(LCA1!=NULL && LCA2!=NULL) return root;
       else if(LCA1==NULL) return LCA2;
       return LCA1;
    }
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      Node *LCA = findLCA(root,first,second);
      string a = "",b = "";
      solve(LCA,a,first);
      solve(LCA,b,second);
      int turn=0;
      for(int i=1;i<a.length();i++) if(a[i]!=a[i-1]) turn++;
      for(int i=1;i<b.length();i++) if(b[i]!=b[i-1]) turn++;
      if(a.length()>=1 && b.length()>=1 && a[0]!=b[0]) turn++;
      return turn;
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends
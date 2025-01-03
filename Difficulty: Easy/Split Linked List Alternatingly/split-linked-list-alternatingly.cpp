//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
               vector<Node*> ans;
        
        if(head==NULL || head->next==NULL){
           ans.push_back(head);
           ans.push_back(NULL);
           return ans;
        }
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* h1 = NULL;
        Node* h2 = NULL;
        Node* curr = head;
        int cnt=0;
        
        while(curr){
         if(cnt%2==0){
             if(head1==NULL){
                 head1=new Node(curr->data);
                 h1=head1;
             }
             else{
                 h1->next=new Node(curr->data);
                 h1=h1->next;
             }
            }
            else{
              if(head2==NULL){
                 head2=new Node(curr->data);
                 h2=head2;
               }
               else{
                 h2->next=new Node(curr->data);
                 h2=h2->next;
               }
            }
            cnt++;
            curr=curr->next;
        }
        ans.push_back(head1);
        ans.push_back(head2);
        return ans;
    
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
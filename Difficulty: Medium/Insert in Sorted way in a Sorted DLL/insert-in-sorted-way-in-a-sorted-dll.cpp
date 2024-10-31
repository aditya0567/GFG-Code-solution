//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
          // take a node to traverse head
        Node* current = head;       

        //create a dll with given value x
        Node* new_node = getNode(x);
        //take another pointer node to track the previous node
        Node* previous = nullptr;
        //check the place where x is less than the node
        while(current && current->data <= x){
            //move the previous to the current
            previous = current;
            //move current to the next
            current = current->next;
        }
        //if the current is head, means the value x is smallest
        if(current == head){
            //new node's next will be current
            new_node->next = current;
            //new node will become head
            head = new_node;
        }
        //if current is nullpointer it means the value x is largest
        else if(!current){
            //point the previous node's next to the new node
            previous->next = new_node;
            //now the new node's previous will become the previous node
            new_node->prev = previous;
        }
        //if the value x 's position is somewhere in the middle
        else{
            //store the previou's next node
            Node* next_node = previous->next;
            // the previous node's next becomes the new node
            previous->next = new_node;
            //now update the prev and next pointers of the new node
            new_node->next = next_node;
            new_node->prev = previous;
        }
        //return the updated dll from head
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends
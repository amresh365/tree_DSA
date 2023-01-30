#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


    void levelOrder(Node * root) 
    {
    if(!root)
     {
    return;
      }
    queue<Node *> q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty())
    {
        Node* current=q.front();
        q.pop();
        if(current->left)
        {
            cout<<current->left->data<<" ";
            q.push(current->left);
        }
        if(current->right)
        {
           cout<<current->right->data<<" ";
           q.push(current->right) ;  
        }
    }
    }

}; 

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}


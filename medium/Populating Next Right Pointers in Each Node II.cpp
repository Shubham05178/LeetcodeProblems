/**
* Leetcode Problem - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
* Author - Shubham Nagaria
* Date - 22nd Feb 2022
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
         Node* curr;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            while(l--){
                curr = q.front();
                q.pop();
                if(l!=0)
                    curr->next = q.front();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};

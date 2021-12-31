/**
* Leetcode Problem - https://leetcode.com/problems/n-ary-tree-preorder-traversal/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Recursive Approach
class Solution {
public:
    void traverse(Node* node,vector<int>& pre){
        if(node==nullptr) return;
        pre.push_back(node->val);
        for(auto & i : node->children)
            traverse(i,pre);
    }
    vector<int> preorder(Node* root) {
        vector<int>pre;
        if(root==NULL) return pre;
        traverse(root,pre);
        return pre;
        
    }
};

// Iterative Approach

 class Solution {
     public:
     vector<int> preorder(Node* root) {
        vector<int>pre;
         if(root==nullptr) return pre;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            pre.push_back(top->val);
            for(int i = top->children.size()-1; i >=0;i--)
                if(top->children[i]!=nullptr) st.push(top->children[i]);
            
        }
         return pre;
     }
 };


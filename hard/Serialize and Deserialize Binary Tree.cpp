/**
* Leetcode Problem -https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
* Author - Shubham Nagaria
* Date - 22nd Feb 2022
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        string s="";
        if(root == NULL) return s;
        TreeNode *front;
        q.push(root);
        while(!q.empty()){
            front= q.front();
            q.pop();
            if(front==NULL){
                s+="$,";
                continue;
            }
            s+=to_string(front->val)+",";
            q.push(front->left);
            q.push(front->right);
        }
        
    return s;
    }   
    void tokenize(string s, vector<string>& p, string del = "," ){
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        p.push_back (s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
     }
     p.push_back( s.substr(start, end - start));
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s =="") return NULL;
        vector<string> st;
        tokenize(s,st);
        TreeNode* root=new TreeNode(stoi(st[0]));
        queue<TreeNode*>q;
        q.push(root);
        for(int i =1 ; i < st.size();){
            TreeNode * temp= q.front();
            q.pop();
            string first= st[i++];
            if((i==st.size()))
                break;
            string second= st[i++];
            if(first!="$"){
                TreeNode * node = new TreeNode(stoi(first));
                 temp->left= node; 
                    q.push(node);
                
            }
            if(second!="$"){
                TreeNode * node = new TreeNode(stoi(second));
                temp->right= node;
                q.push(node);
            }
        }
            
        return root;
        }
    };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

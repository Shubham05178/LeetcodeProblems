/**
* Leetcode Problem - https://leetcode.com/problems/implement-trie-prefix-tree/
* Author - Shubham Nagaria
* Date - 24th Feb 2022
**/
struct TrieNode{
    TrieNode* children[26]={NULL};
    bool isEnd;
    TrieNode(){
        isEnd= false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int n = word.size(), idx;
        for(int i=0; i < n; ++i){
            idx= word[i]-'a';
            if(curr->children[idx]==NULL)
                curr->children[idx]= new TrieNode();
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int n = word.size(), idx;
        for(int i =0; i < n; ++i){
            idx = word[i]-'a';
            if(curr->children[idx]==NULL) return false;
            curr= curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int n = prefix.size(), idx;
        for(int i =0; i < n; ++i){
            idx = prefix[i]-'a';
            if(curr->children[idx]==NULL) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

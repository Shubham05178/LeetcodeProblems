/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-282/problems/counting-words-with-a-given-prefix/
* Author - Shubham Nagaria
* Date - 1st March 2022
**/
struct TrieNode{
    TrieNode* children[26]={NULL};
    int freq=0;
    TrieNode(){}
};
class Solution {
public:
    void insertatTrie(TrieNode* root, string word,string pref , int& l){
        int ll = pref.size();
        for(int i =0; i<ll;i++){
            if(word[i]==pref[i]){
                if(root->children[word[i]-'a']==NULL){
                    root->children[word[i]-'a']= new TrieNode();
                }
                root= root->children[word[i]-'a'];
                root->freq++;
            }
            else
                return;
        }
        l=root->freq;
    }
    int prefixCount(vector<string>& words, string pref) {
        int l =0;
        TrieNode* root = new TrieNode();
        for(auto ii : words)
            insertatTrie(root,ii,pref,l);
        return l;
    }
};


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int l =0;
        int j = pref.size();
        for(string ii : words){
            int i=0;
            while(pref[i]==ii[i] && i<j) i++;
            if(i==j)  l++;
            }
        return l;
    }
};

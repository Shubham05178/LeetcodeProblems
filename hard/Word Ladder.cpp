/**
Leetcode Problem -https://leetcode.com/problems/word-ladder/
Author - Shubham Nagaria
Date - 12th Feb 2022
**/
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent = false;
        unordered_set<string>li;
        for(auto wrd : wordList){
            if(endWord == wrd) isPresent = true;
            li.insert(wrd);
        }
        if(isPresent == false) return 0;
        int depth =0;
        int levl=0;
        queue<string>q;
        string temp,frnt;
        int l = beginWord.size();
        q.push(beginWord);
        while(!q.empty()){
            depth++;
            levl = q.size();
            while(levl--){
                frnt = q.front();
                q.pop();
                for(int i = 0; i < l; ++i){
                    temp=frnt;
                    for(char c ='a'; c<='z';++c){
                        temp[i] = c;
                        if(temp == endWord) return depth+1;
                        if(temp == frnt) continue;
                        if(li.find(temp)!= li.end()){
                            li.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
    return 0; 
    }
};

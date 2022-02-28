/**
* Leetcode Problem - https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
* Author - Shubham Nagaria
* Date - 1st March 2022
**/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l =1;
        int j =0;
        bool fl=true;
        int p = searchWord.size();
        for(int i=0 ;i<sentence.size();i++){
            if(sentence[i]==' '){
                l++;
                fl=true;
                j=0;
            }
            else{
                if(fl && searchWord[j]==sentence[i])
                    j++;
                else{
                    j=0;
                    fl=false;
                }
                if(j==p)
                    return l;
            }
        }
        return -1;
    }
};

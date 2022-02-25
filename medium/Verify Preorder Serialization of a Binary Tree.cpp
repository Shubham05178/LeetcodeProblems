/**
* Leetcode Problem - https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
* Author - Shubham Nagaria
* Date - 26th feb 2022
**/
class Solution {
public:
    vector<string> split(string s){
        vector<string> splitvector;
        string str = "";
        int n = s.size();
        for(int i =0 ; i <=n;i++)
            if(i == n || s[i] == ','){
                splitvector.push_back(str);
                str.clear();
            }
            else{
                str+=s[i];
            }
        return splitvector;
    }
bool isValidSerialization(string preorder) {
        stack<int>st;
        vector<string>splitvector = split(preorder);
        st.push(0);
        int i =1, n =  splitvector.size();
        if(splitvector[0]=="#"){
            if(n==1) return true;
            return false;
        }
        while(i < n){
            if(i<n && splitvector[i]!= "#"){
                if(!st.empty()) {
                    st.top()+=1;
                    if(st.top()==2)st.pop();
                }
                else
                    return false;
                i++;
                st.push(0);
            }
            else{
                if(st.empty()) return false;
                st.top()+=1;
                while( !st.empty() && st.top()==2) st.pop();
                i++;
            }
        }
    return st.empty();
    }
};

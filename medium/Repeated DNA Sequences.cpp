/**
* Leetcode Problem - https://leetcode.com/problems/repeated-dna-sequences/
* Author - Shubham Nagaria
* Date - 20th Jan 2022
**/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char,int>chartoint;unordered_set<long int>p;unordered_set<string>result;
        int n = s.size();
        string str="";
        chartoint['A']=1,chartoint['C']=2,chartoint['G']=3,chartoint['T']=4;
        long int Rhash=0,fivemultiple=1;
        for(int i =0; i<n+1;i++){
            if(i>9 || i==n){
                if(p.find(Rhash)!=p.end()){
                    result.insert(str);
                }
                if(i==n) return vector<string>{result.begin(),result.end()};
            }
            str+=s[i];
            if(i>9){
                p.insert(Rhash);
                Rhash = ((Rhash-chartoint[str[0]])/5)+(chartoint[s[i]]*fivemultiple);
                str.erase(0,1);
            }
            else{
                if (i!=0) fivemultiple=fivemultiple*5;
                Rhash += chartoint[s[i]]*fivemultiple;
            }
        }
        return vector<string>{result.begin(),result.end()};
    }
};

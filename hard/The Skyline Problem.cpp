/**
* Leetcode Problem - https://leetcode.com/problems/the-skyline-problem/
* Author - Shubham Nagaria
* Date - 4th March 2022
**/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    multiset<int, greater<int>>s;
        vector<vector<int>>b,res;
        for( auto i : buildings){
            b.push_back({i[0],i[2],1});
            b.push_back({i[1],i[2],0});
        }
        sort(b.begin(),b.end());
        s.insert(0);
        int curr =0, maxh,p,startorend,h, xp;
        for(int j =0; j<b.size();){
            xp = b[j][0];
            while(j< b.size() && xp==b[j][0]){
                p = b[j][0];
                startorend=b[j][2];
                h = b[j][1];
                if(startorend)
                    s.insert(h);
                else
                    s.erase(s.find(h));
                j++;
            }
            maxh=*(s.begin());
            if(curr != maxh){
                curr = maxh;
                res.push_back({xp,curr});
            }
        }
        return res;
    }
};

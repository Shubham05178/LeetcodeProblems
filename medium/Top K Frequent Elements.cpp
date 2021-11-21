/**
* Leetcode Problem - https://leetcode.com/problems/top-k-frequent-elements/
* Author - Shubham Nagaria
* Date - 20th Nov 2021
**/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size()+1,c=0;
        vector<vector<int>>bucket(n);
        vector<int>res;
        map<int , int >count_map;
        for(int i : nums)
            count_map[i]++;

        for( auto iter = count_map.begin();iter != count_map.end(); iter++)
            bucket[iter->second].push_back( iter->first);
    
        for (int q = n-1; q >= 0; q--)
         {
            for (int t = 0; t < bucket[q].size(); t++)
        {
            
                if(c<k){
                res.push_back(bucket[q][t]);
                c++;
                }
                if(c>=k)
                    break;
                }
            if(c>=k)
                break;
}
        return res;
        
    }
};

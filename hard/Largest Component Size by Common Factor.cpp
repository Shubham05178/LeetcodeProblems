/**
* Leetcode problem - https://leetcode.com/problems/largest-component-size-by-common-factor/
* Author - Shubham Nagaria
* Date- 23rd Nov 2021
**/
class Solution{
    public:
    struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int largestComponentSize(vector<int>& nums) {
	DSU dsu(*max_element(nums.begin(), nums.end()) + 1); //create DSU struct with nodes 0, 1, 2, ... max element of the vector
	for(auto i: nums){
		for(int j = 2;j*j<=i;j++){ //factorize each number
			if(i%j == 0){
				dsu.unite(j, i);
				dsu.unite(i/j, i);
			}
		}
	}
	int ans = 1;
	unordered_map<int, int> freq;
	for(auto i: nums){
		int p = dsu.get(i); //get parent
		freq[p]++;
		ans = max(ans, freq[p]);
	}
	return ans;
}
};

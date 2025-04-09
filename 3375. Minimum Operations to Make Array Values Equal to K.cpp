class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> distinct;
        
        for(int element: nums){
            if(element < k) return -1;
            if(distinct.find(element) == distinct.end() && element > k) distinct.emplace(element);
        }
            return distinct.size();
    }
};

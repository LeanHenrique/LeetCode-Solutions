class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0, left = 0;
        int max = *max_element(nums.begin(), nums.end());
        int frequence = 0;

        for(long long right = 0; right < nums.size(); right++){
            if(nums[right] == max) frequence++;
            while(frequence >= k){
                if(nums[left] == max) frequence--;
                left++;
            }
            count += left;
        }
        return count;
    }
};

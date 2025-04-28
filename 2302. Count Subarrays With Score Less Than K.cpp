class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l = 0, sum = 0, count = 0;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while(sum * (r - l + 1) >= k){
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};

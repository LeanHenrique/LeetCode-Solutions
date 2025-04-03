class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size() < 3)return 0;

        long long MaxValue = nums[0], MaxDif = 0, Maxk = 0, Result = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            MaxDif = max(MaxDif, MaxValue - nums[i]);
            Result = max(Result,MaxDif * nums[i+1]);
            MaxValue = max(MaxValue, (long long) nums[i]);
        }
    if(Result < 0) return 0;
    return Result;
    }
};

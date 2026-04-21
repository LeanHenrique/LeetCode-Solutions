class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> memo(100, -1);

        memo[0] = nums[0];


        return dp(n, nums, memo);
    }

    int dp(int house, vector<int>& nums, vector<int>& memo){
        if(house < 0) return 0;

        if(memo[house] != -1) return memo[house];

        int aux = 0;

           aux = max(dp(house-1, nums, memo), dp(house - 2, nums, memo) + nums[house]);


        memo[house] = aux;

        return aux;
    }
};

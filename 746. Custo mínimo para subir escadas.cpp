class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1);

        memo[0] = 0;
        memo[1] = 0;

        for(int i = 2; i < n + 1; i++){
            memo[i] = min((cost[i-1] + memo[i-1]), (cost[i-2] + memo[i-2]));
        }

        return memo[n];
    }
};

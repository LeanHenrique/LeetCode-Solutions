class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;

        for(auto coin : coins){
            for(int i = coin; i < minCoins.size(); i++){
                minCoins[i] = min(minCoins[i], minCoins[i - coin] + 1);
            }
        }

        if(minCoins[amount] < amount + 1)  return minCoins[amount];

        return -1;
    }
};

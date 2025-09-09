#include <vector>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long acummulator = 0; 
        long long mod = 1000000007;

        for (int i = 2; i <= n; i++) {
            if (i - delay > 0) {
                acummulator = (acummulator + dp[i - delay]) % mod;
            }
            if (i - forget > 0) {
                acummulator = (acummulator - dp[i - forget] + mod) % mod;
            }
            dp[i] = acummulator;
        }

        long long peopleKnow = 0;
        for (int j = n - forget + 1; j <= n; j++) {
            peopleKnow = (peopleKnow + dp[j]) % mod;
        }

        return (int)peopleKnow;
    }
};

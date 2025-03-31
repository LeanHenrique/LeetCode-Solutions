class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        size_t n = weights.size() - 1;

        if (k == 1 || n < k) return 0;

        vector<long long> sum;
        
        for (size_t i = 0; i < n; i++) { 
            sum.push_back(weights[i] + weights[i + 1]);
        }

        sort(sum.begin(), sum.end());
       long long dif = 0;

        for (int i = 0; i < k - 1; ++i){
            dif += sum[n-1-i] - sum[i];
            }
            return dif;
    }
};

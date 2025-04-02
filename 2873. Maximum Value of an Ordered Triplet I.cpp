
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if (nums.size() < 3) return 0;  // Proteção contra entradas inválidas
        
        long long result = 0;

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];

            for (int j = i + 1; j < nums.size(); j++) { 
                int second = nums[j];

                for (int k = j + 1; k < nums.size(); k++) { 
                    int three = nums[k];
                    long long triplet = (long long)(first - second) * three;
                    result = max(result, triplet);
                }
            }
        }
        
        return result;
    }
};

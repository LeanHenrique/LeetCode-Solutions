class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        int aux = 0;

        for(int i = 0; i < nums.size(); i++){
            aux = nums[i];
            while(!result.empty() && gcd(aux, result.back()) > 1){
                aux = lcm(aux, result.back());
                result.pop_back();
            }
            result.push_back(aux);
        }
        return result;
    }
};

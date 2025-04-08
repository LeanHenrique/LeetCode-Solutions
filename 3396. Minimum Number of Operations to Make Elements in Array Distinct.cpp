class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cont = 0;
        
        while (!nums.empty()) {
            unordered_map<int, int> freq;
            bool hasDuplicate = false;

            for (int num : nums) {
                freq[num]++;
                if (freq[num] > 1) {
                    hasDuplicate = true;
                }
            }

            if (hasDuplicate && nums.size() >= 3) {
                nums.erase(nums.begin(), nums.begin() + 3);
                cont++;
            } else if(hasDuplicate && nums.size() < 3){
                int size = nums.size();
                nums.erase(nums.begin(), nums.begin() + size);
                cont++;
            }else{
                break; 
            }
        }

        return cont;
    }
};

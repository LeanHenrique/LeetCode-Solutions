class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + 2 < nums.size()) {  
                    nums[i] = 1;
                    nums[i + 1] = 1 - nums[i + 1];  
                    nums[i + 2] = 1 - nums[i + 2];  
                    operations++;  
                }else{
                    operations = -1;
                    return operations;
                }
            }
        }
        return operations;
    }
};

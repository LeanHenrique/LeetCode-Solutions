class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int a = 0,b = 0,c = 0;
        for(int i = 0; i + 2 < nums.size(); i++){
            
            a = nums[i];
            b = nums[i+1];
            c = nums[i+2];
            
            if(b % 2 == 0 && a+c == b/2) count++;
        }
        return count;
    }
};

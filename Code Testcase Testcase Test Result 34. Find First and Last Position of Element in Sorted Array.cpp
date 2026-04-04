class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        
        while(left >= 0 && right < nums.size()){
            if(nums[left] == target && nums[right] == target){
                return {left, right};
                }
                if(nums[left] != target) left++;
                if(nums[right] != target) right--;
            }
            return {-1, -1};
        }
};

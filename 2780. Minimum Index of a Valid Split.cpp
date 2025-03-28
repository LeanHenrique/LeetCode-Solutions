class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> frequence;
        int n = nums.size();
        for(int num : nums){
            frequence[num]++;
        }

        int maxFreq = 0; 
        int mostFrequent = nums[0];
        for (auto& pair : frequence) {
             if (pair.second > maxFreq) {
                maxFreq = pair.second;
                mostFrequent = pair.first;
        }
    }
    int leftcount = 0; 
    int totalcount = maxFreq;
    for(int i = 0; i < n; i++){
        if(nums[i] == mostFrequent){
            leftcount++;
        }
        int rightcount = totalcount - leftcount;
        if((leftcount * 2 > (i + 1)) && (rightcount * 2 > (n - (i + 1)))){
            return i;
        }
    }
    return -1;
    }
};

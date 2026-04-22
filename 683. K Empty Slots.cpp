class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> turned(n + 1, 0);
        int total = n + 1;

        
        for(int i = 0; i < bulbs.size(); i++){    
            int aux = bulbs[i];
            turned[aux] = i+1;
        }

        int left = 1;
        int right = left + k + 1;
        for(int i = 1; right < turned.size(); i++){
            if(i == right){
                total = min(total, max(turned[left], turned[right]));

                left = i;
                right = left + k + 1;
            }else if(turned[i] < turned[left] || turned[i] < turned[right]){
                left = i;
                right = left + k + 1;
            }
        }

        if(total == n+1) return -1;

        return total;
    }             
};

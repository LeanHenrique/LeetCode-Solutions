class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0, v = 0, x = 0, y = 0, z = 0;
        for(int i = 0; i < arr.size(); i++){
            x = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                y = arr[j];
                for(int k = j+1; k < arr.size(); k++){
                    z = arr[k];
                    if(abs(x-y) > a) continue;
                    if(abs(y-z) > b) continue;
                    if(abs(x-z) > c) continue;
                    result++;
                }
            }
        }
        return result;
    }
};

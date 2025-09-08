class Solution {
public:  

    bool ZeroVerify(int n){
        int aux = n;
        while(aux > 0){
            if(aux % 10 == 0)return true;
            aux = aux / 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int first = 1;
        int second = n-1;

        if(!ZeroVerify(second)) return{first, second};
        while(ZeroVerify(first) || ZeroVerify(second)){
            first++;
            second--;
        }
        return {first, second};
    }
};

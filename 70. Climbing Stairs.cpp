class Solution {
public:
    int climbStairs(int n) {
       if(n<=2)return n;

       vector<int> climb(n + 1, 0);
    
       climb[1] = 1;
       climb[2] = 2;

       for(int i = 3; i <= n; i++){
        climb[i] = climb[i-1] + climb[i-2];
       }

       return climb[n];

    }
};


//second solution
class Solution {
public:
    int climbStairs(int n) {
       if(n == 1) return 1;

       int first = 1;
       int second = 2;
       int third = 0;

       for(int i = 2; i < n; i++){
        third = first + second;
        first = second;
        second = third; 
        }

        return second;
    }

};

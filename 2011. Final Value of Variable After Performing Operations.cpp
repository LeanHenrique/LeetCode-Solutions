class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(const auto operation : operations){
            if(operation == "--X" || operation == "X--"){
                count--;
            }
             if(operation == "++X" || operation == "X++"){
                count++;
            }
        }
        return count;
    }
};

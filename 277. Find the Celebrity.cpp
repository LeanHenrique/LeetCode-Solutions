/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int possibleCandidate = 0;
        
        for(int i = 0; i < n; i++){
            if(possibleCandidate == i) continue;
            if(knows(possibleCandidate, i)) possibleCandidate = i;
        }

        if(verifyCandidate(possibleCandidate, n)) return possibleCandidate;

        return - 1;
    }

    bool verifyCandidate(int candidate, int sizeGraph){
        for(int i = 0; i < sizeGraph; i++){
            if(candidate == i) continue;
            if(knows(candidate, i) || !knows(i, candidate)) return false;
        }
        return true;
    }
};

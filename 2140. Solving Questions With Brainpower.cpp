class Solution {
public:
    vector<bool> verify;
    vector<long long> mem;

    long long memoization(int i, vector<vector<int>>& questions) {
        if (i >= questions.size()) return 0; 

        if (verify[i]) return mem[i];

        verify[i] = true; 

        int prox = i + questions[i][1] + 1;

        long long solver = questions[i][0] + memoization(prox, questions); 
        long long skip = memoization(i + 1, questions); 

        return mem[i] = max(solver, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        mem.resize(n, -1); 
        verify.resize(n, false); 
        return memoization(0, questions); 
    }
};

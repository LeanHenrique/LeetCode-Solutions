class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int count = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1 && j != 0) mat[i][j] = mat[i][j-1] + 1;
                
                int minLarg = mat[i][j];
                
                for(int k = i; k >= 0 && minLarg > 0; k--){
                    minLarg = min(minLarg, mat[k][j]);
                    count += minLarg;
                } 
            }
        }
        return count;
    }
};

class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<int, int> freq;
        int sum = 0;
        
        for(auto c : tiles){
            freq[c]++;
        }

        dfs(freq, sum); 

        return sum;
    }

    void dfs(map<int,int>& freq, int& sum){
       for(auto& pair : freq){
        char letter = pair.first;
        int& quantidade = pair.second;
        
        if(quantidade > 0){
            sum++;
            quantidade--;

            dfs(freq, sum);

            quantidade++;
        }
     }
  }
};

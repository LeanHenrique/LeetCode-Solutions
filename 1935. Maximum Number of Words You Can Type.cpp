class Solution {
public:

    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken (26,false);
        int count = 0, countsize = 0;
        stringstream Words(text);
        for(const auto letter : brokenLetters){
            int num = letter - 'a';
            broken[num] = true;
        }
        string word;
        while(Words >> word){
            countsize++;
            for(const auto letter : word){
                int ASC = letter - 'a';
                if(broken[ASC]){
                    count++;
                    break;
                }
            }
        }
        return countsize - count;
    }
};

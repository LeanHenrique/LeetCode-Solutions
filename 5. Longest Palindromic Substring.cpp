class Solution {
public:
    string longestPalindrome(string s) {
        string max_str(1,s[0]);
        int min_i = 0, max_i = 0;
        for(int i = 0; i < s.length(); i++){
            verifyPalindrome(s, i, i, max_i, min_i);
            verifyPalindrome(s, i, i+1, max_i, min_i);
        }
        max_str = s.substr(min_i, max_i - min_i + 1);
        return max_str;
    }

    void verifyPalindrome(string& s, int left, int right, int& max_i, int& min_i){
        while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]){
            if((max_i - min_i + 1) < (right - left  + 1)){
                max_i = right;
                min_i = left;
            }
            left--;
            right++;
        }
    }
};

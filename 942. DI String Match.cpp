class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> result;
        int left = 0, right = s.length();

        if(s[0] == 'I'){
            result.push_back(0);
            left++;
        } 
        if(s[0] == 'D'){
            result.push_back(n);
            right --;
        }

        for(int i = 1; i < n; i++){
            if(s[i] == 'I'){
                result.push_back(left);
                left++;
            }

            if(s[i] == 'D'){
                result.push_back(right);
                right--;
            }
        }

        if(s[n-1] == 'D'){
            result.push_back(left);
        }else{
            result.push_back(right);
        }

        return result;
    }
};

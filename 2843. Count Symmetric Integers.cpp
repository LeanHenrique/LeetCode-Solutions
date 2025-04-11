class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;

        for(int i = low; i <= high; i++){ 
            string num = to_string(i);
            
            if(num.length() % 2 != 0) continue; 

            int half = num.length() / 2;

            string first = num.substr(0, half);
            string second = num.substr(half);

            int somf = 0, soms = 0; 

            for(char f : first) somf += f - '0';
            for(char s : second) soms += s - '0';

            if(somf == soms) result++;
        }

        return result;
    }
};

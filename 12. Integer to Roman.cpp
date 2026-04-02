class Solution {
public:
string intToRoman(int num) {
 map<int, string, greater<int>> romanAlgarisms;
 string result = "";
 romanAlgarisms[1000] = "M";
 romanAlgarisms[900] = "CM";
 romanAlgarisms[500] = "D";
 romanAlgarisms[400] = "CD";
 romanAlgarisms[100] = "C";
 romanAlgarisms[90] = "XC";
 romanAlgarisms[50] = "L";
 romanAlgarisms[40] = "XL";
 romanAlgarisms[10] = "X";
 romanAlgarisms[9] = "IX";
 romanAlgarisms[5] = "V";
 romanAlgarisms[4] = "IV";
 romanAlgarisms[1] = "I";

 for(auto& [value, Algarism] : romanAlgarisms){

    while(num >= value){
        result+= Algarism;
        num = num - value;
    }

 }
 return result;
}
};

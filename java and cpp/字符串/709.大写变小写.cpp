//大写变小写、小写变大写 : 字符 ^= 32;
//大写变小写、小写变小写 : 字符 |= 32;
//小写变大写、大写变大写 : 字符 &= -33;

class Solution {
public:
    string toLowerCase(string str) {
        for(auto &i : str){
            i |= 32;
        }
        return str; 
    }
};

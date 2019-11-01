//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

//大写变小写、小写变大写 : 字符 ^= 32;
/大写变小写、小写变小写 : 字符 |= 32;
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

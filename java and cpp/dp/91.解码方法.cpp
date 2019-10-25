/*一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

// 斐波那契数列的变种
//考虑0不能单独解码的情况11111
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp = {0, 1};
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i - 1] != '1' && (s[i - 1] != '2' || s[i] > '6')) {
                dp[i % 2] = 0;
            }
            if (s[i] > '0') {
                dp[i % 2] += dp[(i + 1) % 2];
            }
        }
        return dp[(s.size() + 1) % 2];
    }
};

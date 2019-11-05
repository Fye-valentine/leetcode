/*有 1000 只水桶，其中有且只有一桶装的含有毒药，其余装的都是水。它们从外观看起来都一样。如果小猪喝了毒药，它会在 15 分钟内死去。
问题来了，如果需要你在一小时内，弄清楚哪只水桶含有毒药，你最少需要多少只猪？
回答这个问题，并为下列的进阶问题编写一个通用算法。
进阶:
假设有 n 只水桶，猪饮水中毒后会在 m 分钟内死亡，你需要多少猪（x）就能在 p 分钟内找出 “有毒” 水桶？这 n 只水桶里有且仅有一只有毒的桶。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/poor-pigs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//普通版： 一只猪最多可以喝四次水，可找到五桶水中的毒药，两只猪最多可以验证5*5=25桶水（一次喝下四桶水）。
//进阶版：一只猪最多可以找到y=p/m+1桶水中的毒药，所以有猪的个数X，使y^x>=n,即x*log(y)>=log(n)。

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int decimal = minutesToTest/minutesToDie + 1;
        int pig = ceil(log(buckets)/log(decimal));
        return pig;
    }
};

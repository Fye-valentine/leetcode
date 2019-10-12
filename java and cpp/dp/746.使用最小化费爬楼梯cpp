/*数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[3];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<cost.size(); i++){
            dp[2]=min(dp[0],dp[1])+cost[i];
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return min(dp[0],dp[1]);
    }
};

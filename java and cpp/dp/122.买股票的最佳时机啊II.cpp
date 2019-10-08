/*给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。*/

class Solution {
    public int maxProfit(int[] prices) {
        int lirun=0;
        int I=0;
        for (int i=0; i<prices.length-1; i++){
            if(prices[i]>prices[i+1]){
                lirun+=prices[i]-prices[I];
                I=i+1;
            }      
        }
        if(prices.length>=2){
            if(prices[prices.length-1]>=prices[prices.length-2]) lirun+=prices[prices.length-1]-prices[I];    
        }
        return lirun;
    }
}

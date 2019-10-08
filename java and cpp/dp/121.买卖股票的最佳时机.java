/*Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.*/
//动态规划
//第i天最大利润为：lirun=Math.max(lirun,prices[i]-min);

class Solution {
    public int maxProfit(int[] prices) {
        int lirun=0;
        if(prices.length>0){
            int min=prices[0];
            for(int i=0; i< prices.length; i++){
                lirun=Math.max(lirun,prices[i]-min);
                min=Math.min(min,prices[i]);
            }
        }
        return lirun;
    }
}

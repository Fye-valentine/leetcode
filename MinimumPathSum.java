//动态规划
//dp[i][j]表示当前节点的值
//该节点（非第一行第一列）值的递推公式为Math.min(dp[i][j-1],dp[i-1][j])+grid[i][j]
class Solution {
    public int minPathSum(int[][] grid) {
        int[][] dp= new int[grid.length+1][grid[0].length+1];
        dp[0][0]=grid[0][0];
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(j==0&&i!=0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
                else if(i==0&j!=0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }
                else if(i!=0&&j!=0){
                    dp[i][j]=Math.min(dp[i][j-1],dp[i-1][j])+grid[i][j];
                }
            }
        }
        return dp[grid.length-1][grid[0].length-1];
    }
}

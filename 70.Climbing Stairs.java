//动态规划
//斐波那契数列
class Solution {
    public int climbStairs(int n) {
        int[] c = new int[4];
        c[1]=1;
        c[2]=2;
        if(n==1) return 1;
        if(n>2){
            for (int i=2; i<n; i++){
                c[3]=c[1]+c[2];
                c[1]=c[2];
                c[2]=c[3];
            }
        }
        return c[2];
    }
}

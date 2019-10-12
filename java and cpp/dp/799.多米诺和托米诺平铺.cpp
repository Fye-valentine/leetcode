/*有两种形状的瓷砖：一种是 2x1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。

XX  <- 多米诺

XX  <- "L" 托米诺
X
给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/domino-and-tromino-tiling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
    public int numTilings(int N) {
        int a[] = new int[4];
        a[0]=1;
        a[1]=2;
        a[2]=5;
        for(int i=3; i<N; i++){
            a[3]=(a[0]%1000000007+a[2]*2%1000000007)%1000000007;
            a[0]=a[1];
            a[1]=a[2];
            a[2]=a[3];
        }
        return N<=3?a[N-1]:a[3];
    }
}

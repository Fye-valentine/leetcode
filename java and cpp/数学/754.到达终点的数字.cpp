/*在一根无限长的数轴上，你站在0的位置。终点在target的位置。

每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。

返回到达终点需要的最小移动次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reach-a-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int reachNumber(int target) {
        if(target<0) target=-target;
        int i=1;
        while(true){
            int x=i*(i+1)/2-target;
            if(x>=0&&x%2==0) return i;
            i++;
        }    
    }
};

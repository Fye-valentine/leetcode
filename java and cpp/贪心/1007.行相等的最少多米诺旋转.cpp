/*在一排多米诺骨牌中，A[i] 和 B[i] 分别代表第 i 个多米诺骨牌的上半部分和下半部分。
（一个多米诺是两个从 1 到 6 的数字同列平铺形成的 —— 该平铺的每一半上都有一个数字。）

我们可以旋转第 i 张多米诺，使得 A[i] 和 B[i] 的值交换。

返回能使 A 中所有值或者 B 中所有值都相同的最小旋转次数。

如果无法做到，返回 -1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-domino-rotations-for-equal-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/



class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<vector<int>> d(6,{0,0});
        int len=A.size();
        int res=1e9;
        for(int i=0; i<len; i++){
            d[A[i]-1][0]++;
            d[B[i]-1][1]++;
        }//统计数组中各个元素的个数，个数>=数组的长度即可选作候选的元素
        for(int i=0; i<6; i++){
            if(d[i][0]+d[i][1]>=len){
                int flag=0;
                for(int j=0; j<len; j++){
                    if(A[j]!=i+1&&B[j]!=i+1){
                        flag=1;
                        break;
                    }//如果有一位两个数组中均不含有候选元素，则该元素不符合条件
                    
                }
                if(flag==0){
                    int temp=(len-d[i][0])<(len-d[i][1])?(len-d[i][0]):(len-d[i][1]);
                    res=res<temp?res:temp;
                }
            }
        }    
        return res==1e9?-1:res;//若无满足条件的元素则返回-1
    }
};

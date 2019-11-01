/*给你一个正整数的数组 A（其中的元素不一定完全不同），
请你返回可在 一次交换（交换两数字 A[i] 和 A[j] 的位置）后得到的、按字典序排列小于 A 的最大可能排列。
如果无法这么操作，就请返回原数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/previous-permutation-with-one-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//从数组末尾开始遍历找到第一个非递减的成员，之后交换该成员与其之后的比他小的最大的成员，可得出答案。

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i=A.size()-2; i>=0; i--){
            if(A[i]>A[i+1]){
                int j=A.size()-1;
                while(A[j]>=A[i]||(j>0&&A[j]==A[j-1])) j--;
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                break;
            }
        }
        return A;   
    }
};

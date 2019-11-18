/*给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。

找出 A 中的坡的最大宽度，如果不存在，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-ramp
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//使用单调栈

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> mystack;
        int res=0;
        for(int i=0; i<A.size(); i++){
            if(mystack.empty()||A[i]<A[mystack.top()])
                mystack.push(i);
        }
        for(int i=A.size()-1; i>0; i--){
            while(!mystack.empty()&&A[i]>=A[mystack.top()]){
                int temp=i-mystack.top();
                res=res>temp?res:temp;
                mystack.pop();
            }          
        }   
        return res; 
    }
};

/*给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-well-performing-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//使用单调栈和前缀和；

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        stack<int> mystack;
        int len=hours.size();
        vector<int> pre(len+1, 0);
        int res=0;
        for(int i=1; i<=len; i++){
            pre[i]=pre[i-1]+(hours[i-1]>8?1:-1);
        }
        for(int i=0; i<=len; i++){
            if(mystack.empty()||pre[i]<pre[mystack.top()])
                mystack.push(i);
        }
        for(; len>=0; len--){
            while(!mystack.empty()&&pre[len]-pre[mystack.top()]>0){
                int temp=len-mystack.top();
                res=res>temp?res:temp;
                mystack.pop();
            }
        }
        return res;
    }
};

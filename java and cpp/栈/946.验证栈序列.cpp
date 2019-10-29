/*给定 pushed 和 popped 两个序列，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-stack-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//初始化一个栈，之后模拟栈的出入。

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p1=0;
        int p2=0;
        int length=pushed.size();
        if(length==0) return true;
        for (p1=0; p1<length; p1++){
            s.push(pushed[p1]);
            while(!s.empty()&&p2<length&&s.top()==popped[p2]){
                s.pop();
                p2++;
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};

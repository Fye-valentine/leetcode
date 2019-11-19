/*给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。*/

//找到包含每个柱子的最大矩形面积
//使用单调递减栈找到距离柱子左右最近的第一个比该柱子小的柱子即为边界。
//比较找出最大值。

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mystack;
        int res=0;
        int len=heights.size();
        vector<int> temp(len+2,-1);
        for(int i=0; i<len; i++){
            temp[i+1]=heights[i];
        }
        for(int i=0; i<len+2; i++){
            if(mystack.empty()||temp[i]>=temp[mystack.top()])
                mystack.push(i);
            else{
                while(temp[i]<temp[mystack.top()]){
                    int Temp=mystack.top();
                    mystack.pop();
                    int s=(i-mystack.top()-1)*temp[Temp];
                    res=res>s?res:s;
                }
                mystack.push(i);
            }
        }         
        return res;
    }
};

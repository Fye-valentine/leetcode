/*给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。*/
//首尾双指针
//移动长棍子只会使面积变小
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=height.size();
        int max=0;
        int i=0;
        int j=l-1;
        while(i!=j){
            if(height[i]>height[j]){
                max=max>(j-i)*height[j]?max:(j-i)*height[j];
                j--;
            }
            else{
                max=max>(j-i)*height[i]?max:(j-i)*height[i];
                i++;
            }
        }
        return max;
    }
};

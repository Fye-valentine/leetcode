//首位双指针
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

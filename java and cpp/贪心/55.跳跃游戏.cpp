/*给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。*/

//k表示前i个点可到达的最远距离，如果i>k则到达不了最后一个位置。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=0;
        for (int i=0; i<nums.size(); i++){
            if(i>k)
                return false;
            k=max(k,nums[i]+i);
        }
        return true;
    }
};

//动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=nums.size();
        if(l==0){
            return 0;
        }
        if(l==1){
            return nums[0];
        }
        int dp=nums[0];
        int max=nums[0];
        for (int i=1; i<l; i++){
            dp=nums[i]>dp+nums[i]?nums[i]:dp+nums[i];
            max=max>dp?max:dp;
        }
        return max;
    }
};

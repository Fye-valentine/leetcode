//给定一个未排序的整数数组，找到最长递增子序列的个数。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(nums.size()==0) return 0;
        int max=1;
        int res=0;
        vector<vector<int>> dp(len, {1,1});//二维dp数组，分别记录该位的最长子序列的长度和个数
        for(int i=0; i<len; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(dp[i][0]<dp[j][0]+1){
                        dp[i]={dp[j][0]+1, dp[j][1]};
                    }
                    else if(dp[i][0]==dp[j][0]+1){
                        dp[i][1]+=dp[j][1];
                    }
                    max=max>dp[i][0]?max:dp[i][0];
                }
            }
        }    
        int index=0;
        for(int i=0; i<len; i++){
            if(dp[i][0]==max)
            res+=dp[i][1];
        }
        return res;
    }
};

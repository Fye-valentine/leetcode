class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int flag=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==nums[res]) 
                flag++;
            else
                flag--;
            if(flag<0){
                res=i;
                flag=0;
            }
        }    
        return nums[res];    
    }
};

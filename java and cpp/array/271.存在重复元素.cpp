/*给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。*/

//使用set的无重复元素的特性判断是否有重复元素。

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};

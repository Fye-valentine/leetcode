//给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
//时间复杂度限定O(lgn)。
//判断mid的奇偶以及左右相等四种情况进行二分查找。
class Solution {
public:
    int res;
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1||nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        erfen(nums, 0, nums.size()-1);
        return res;
    }
    void erfen(vector<int>& nums, int left, int right){
        int mid= (left+right)/2;
        if(left<=right){
            if(mid!=0&&mid!=nums.size()&&nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                res = nums[mid];
            }
            if(mid%2==0&&nums[mid]==nums[mid+1]) erfen(nums,mid+1, right);
            if(mid%2==0&&nums[mid]==nums[mid-1]) erfen(nums, left, mid-1);
            if(mid%2!=0&&nums[mid]==nums[mid-1]) erfen(nums,mid+1, right);
            if(mid%2!=0&&nums[mid]==nums[mid+1]) erfen(nums,left,mid-1);
        }
    }
};

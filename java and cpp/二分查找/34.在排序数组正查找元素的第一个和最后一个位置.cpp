/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//二分查找，先确定左边界，再确定右边界。

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int l=0,r=nums.size()-1;
        if(nums.size()==0) return res;
        int mid1,l1,r1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1; 
        }    
        if(nums[l]!=target) return res;
        res[0]=l;
        r=nums.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid+1;
            else r=mid;
        }
        res[1]=r-1;
        return res;
    }
};

//转换成前后双指针加两指针中间的另一个指针
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list1 = new ArrayList<>();
        int j;
        int k;
        for(int i=0;i<nums.length; i++){
            if(nums[i]>0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
			j=i+1;
			k=nums.length-1;
			while(j<k){
				if(nums[j]+nums[k]+nums[i]<0)
					j++;
				else if(nums[j]+nums[k]+nums[i]>0)
					k--;
				else if(nums[j]+nums[k]+nums[i]==0){
					list1.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while(j<k&&nums[j]==nums[++j]);
                    while(j<k&&nums[k]==nums[--k]);
				}
			}
		} 
        return list1;
    }
}

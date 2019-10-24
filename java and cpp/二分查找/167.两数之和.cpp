class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] sum = new int[2];
        int i=0;
        int j=numbers.length-1;
        int s;
        while(i<=j){
            s=numbers[i]+numbers[j];
            if(s<target)
                i++;
            else if(s>target)
                j--;
            else{
                sum[0]=i+1;
                sum[1]=j+1;
                break;
            }
        }
        return sum;
    }
}

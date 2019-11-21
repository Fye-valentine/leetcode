class Solution {
    public int findComplement(int num) {
        int res = 0;
        int i = 0;
        while(num>0){
          res +=  ((num&1)==0?1:0)*(1<<i++);
          num = num >> 1;
        }
        return res;
    }
}

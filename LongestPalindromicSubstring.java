class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        int max=0;
        String S=new String();
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<s.length()-i;j++){
                if(s.charAt(j)==s.charAt(j+i)&&(i<3||dp[j+1][j+i-1])){
                    dp[j][j+i]=true;
                    if(max<=i){
                        max=i;
                        S=s.substring(j,j+i+1);
                    }
                }
            }
        }
        return S;
    }
}

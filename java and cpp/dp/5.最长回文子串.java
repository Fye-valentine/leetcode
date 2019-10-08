/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。*/
//动态规划
//dp[i][j]表示从i开始到j结束的子串为回文
//dp[i][j]为回文则dp[i+1][j-1]为回文
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

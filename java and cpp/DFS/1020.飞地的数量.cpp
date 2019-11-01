/*给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。

移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。

返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-enclaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//找到边界上的地进行深度优先搜索，把经过的地变成0，最后遍历找出非0的地的数量即为结果。

class Solution {
public:
    int res = 0;
    int numEnclaves(vector<vector<int>>& A) {
        int ans=0;
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(i-1<0||i+1==A.size()||j-1<0||j+1==A[0].size()){
                    if(A[i][j]==1) dfs(A,i,j);
                }
            }
        }
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j]==1) ans++;  
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& A, int x, int y){
        if(x<0||x>=A.size()||y<0||y>=A[0].size()||A[x][y]==0) return;
        A[x][y]=0;
        dfs(A, x-1, y);
        dfs(A, x+1, y);
        dfs(A, x, y-1);
        dfs(A, x, y+1);
    }
};

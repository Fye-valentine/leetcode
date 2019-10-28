/*给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x1=grid.size(); 
        if(!x1) return 0;
        int y1=grid[0].size();
       
        int res=0;        
        for(int x=0; x<x1; x++){
            for(int y=0; y<y1; y++){
                if(grid[x][y]=='1'){
                    res++;
                    dfs(grid, x, y);
                }
            }   
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        int x1=grid.size();
        int y1=grid[0].size();
        grid[x][y]='0';
        if(x-1>=0 && grid[x-1][y]=='1') dfs(grid, x-1, y);
        if(x+1<x1 && grid[x+1][y]=='1') dfs(grid, x+1, y);
        if(y-1>=0 && grid[x][y-1]=='1') dfs(grid, x, y-1);
        if(y+1<y1 && grid[x][y+1]=='1') dfs(grid, x, y+1);
    }
};

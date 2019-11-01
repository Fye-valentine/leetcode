/*给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//与1020题（飞地的数量）相似。

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int x=0; x<board.size(); x++){
            for(int y=0; y<board[0].size(); y++){
                if(x==0||x==board.size()-1||y==0||y==board[0].size()-1)
                    if(board[x][y]=='O') dfs(board, x, y);
            }
        }
        for(int x=0; x<board.size(); x++){
            for(int y=0; y<board[0].size(); y++){
                if(board[x][y]=='O') board[x][y]='X';
                if(board[x][y]=='f') board[x][y]='O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x<0||x==board.size()||y<0||y==board[0].size()||board[x][y]=='X'||board[x][y]=='f') 
            return;
        board[x][y]='f';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y+1);
        dfs(board, x, y-1);
    }
};

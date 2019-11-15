/*在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

「黑皇后」在棋盘上的位置分布用整数坐标数组 queens 表示，「白国王」的坐标用数组 king 表示。

「黑皇后」的行棋规定是：横、直、斜都可以走，步数不受限制，但是，不能越子行棋。

请你返回可以直接攻击到「白国王」的所有「黑皇后」的坐标（任意顺序）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queens-that-can-attack-the-king
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool inVector(int x, int y, vector<vector<int>>& b)
    {
        for (int i = 0; i < b.size(); i++)
        {		
            if (x == b[i][0] && y == b[i][1])		
            {			
                return true;	
            }	
        }	
        return false;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int x = king[0];	
        int y = king[1];	
        vector<vector<int>> res;	
        // 往右	
        for (int i = x + 1; i <= 7; i++)	
        {		
            if (inVector(i, y, queens))		
            {					
                res.push_back({i,y});
                break;
            }
            
        }	
        // 往左	
        for (int i = x - 1; i >= 0; i--)
        {	
            if (inVector(i, y, queens))	
            {					
                res.push_back({i,y});
                break;	
            }
            
        }	
        // 往上	
        for (int i = y + 1; i <= 7; i++)	
        {		
            if (inVector(x, i, queens))		
            {				
                res.push_back({x,i});	
                break;
            }
            
        }	
        // 往下
        for (int i = y - 1; i >= 0; i--)
        {		
            if (inVector(x, i, queens))		
            {						
                res.push_back({x,i});		
                break;
            }
            
        }
        // 往右上	    
        for (int i = x + 1,j=y-1; i <= 7&&j>=0; i++,j--)	
        {		
            			
            if (inVector(i, j, queens)&& (i+j == x+y))			
            {								
                res.push_back({i,j});
                break;
            }	
        }	
        // 往右下	
        for (int i = x + 1,j=y+1; i <= 7&&j<=7; i++,j++)	
        {		
            		
            if (inVector(i, j, queens)&& (i-x == j-y))		
            {			
               				
                res.push_back({i,j});	
                break;
            }
            
        }	
        // 往左上
        for (int i = x - 1,j=y-1; i >=0&&j>=0; i--,j--)	
        {	
            		
            if (inVector(i, j, queens)&& (x-i == y-j))		
            {							
                res.push_back({i,j});	
                break;
            }     	
        }	
        // 往左下	
        for (int i = x - 1,j=y+1; i >= 0&&j<=7; i--,j++)	
        {		
            		
            if (inVector(i, j, queens)&& (i+j==x+y))		
            {					
                res.push_back({i,j});
                break;	
            }    
        }	
        return res;    
    }
};

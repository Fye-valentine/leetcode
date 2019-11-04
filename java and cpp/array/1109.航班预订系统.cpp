/*这里有 n 个航班，它们分别从 1 到 n 进行编号。
我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。
请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。
示例：
输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/corporate-flight-bookings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//差分数组
//最开始res[i]中存储值x=res[i]-res[i-1]
//最后遍历res[i]=x+res[i-1]，也就是res[i]+=res[i-1]

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1,0);
        
        for(int i=0; i<bookings.size(); i++){
            res[bookings[i][0]-1]+=bookings[i][2];
            res[bookings[i][1]]-=bookings[i][2];
        }
        for(int i=1; i<n; i++){
            res[i]+=res[i-1];
        }
        res.pop_back();
        return res;
    }
};

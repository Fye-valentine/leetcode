/*给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。
如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/asteroid-collision
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//栈思想实现
//只有三种情况入栈
//方向相同，方向相背
//方向相向的时候判断大小进行处理

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> temp;
        temp.push_back(asteroids[0]);
        int flag=1;
        while(flag<asteroids.size()){
            if(temp.size()==0){
                temp.push_back(asteroids[flag]);
                flag++;
            }
            else if(temp.back()<0) {
                temp.push_back(asteroids[flag]);
                flag++;
                continue;    
            }
            else{
                if(asteroids[flag]>0){
                    temp.push_back(asteroids[flag]);
                    flag++;
                }
                else{
                    if(abs(asteroids[flag])==temp.back()){
                        temp.pop_back();
                        flag++;
                        continue;
                    }
                    if(abs(asteroids[flag])>temp.back()) {
                        temp.pop_back();
                        continue;
                    }
                    if(abs(asteroids[flag])<temp.back()) {
                        flag++;
                        continue;
                    }
                }
            }
        }
        return temp;
    }
};

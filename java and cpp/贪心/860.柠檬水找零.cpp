/*在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
注意，一开始你手头没有任何零钱。
如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lemonade-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//模拟购买过程，从大面值的纸币开始找零。

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5)
            return false;
        int five=1;
        int ten=0;
        for(int i=1; i<bills.size(); i++){
            if(bills[i]==5)
                five++;
            if(bills[i]==10){
                five--;
                ten++;
            }
            if(bills[i]==20){
                if(ten>=1){
                    ten--;
                    five--;
                }
                else if(ten==0){
                    five-=3;
                }
            }
            if(five<0)
                return false;
        }
        return true;
    }
};

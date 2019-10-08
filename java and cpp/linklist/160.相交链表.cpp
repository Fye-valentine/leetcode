//找到两个相交链表的交点

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i=0;
        int j=0;
        ListNode *heada=headA;
        ListNode *headb=headB;
        if(headA==NULL||headB==NULL)
            return NULL;
        while(heada!=NULL||headb!=NULL){
            if(heada!=NULL){
                heada=heada->next;
                i++;
            }
            if(headb!=NULL){
                headb=headb->next;
                j++;
            }
        }
        ListNode *result=headB;
        ListNode *result2=headB;
        if(i<j){
            i=j-i;
            result=headB;
            result2=headA;
        }
        else{
            i=i-j;
            result=headA;
            result2=headB;
        }
        j=0;
        while(result!=result2&&result!=NULL&&result2!=NULL){
            if(j<i){
                result=result->next;
            }
            else{
                result=result->next;
                result2=result2->next;
            }
            j++;
        }
        return result;
    }
};

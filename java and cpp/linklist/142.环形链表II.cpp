/*给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。*/

//快慢双指针，弗洛伊德算法。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==NULL)
            return NULL;
        while(true){
            slow=slow->next;
            if(fast==NULL||fast->next==NULL){
                return NULL;
            }
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        while(head!=fast){
            head=head->next;
            fast=fast->next;
        }
        return head;
    }
};

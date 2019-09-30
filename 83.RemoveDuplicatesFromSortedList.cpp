//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* l2=head;
        while(l2!=NULL&&l2->next!=NULL){
            if(l2->val==l2->next->val&&l2!=NULL){
                l2->next=l2->next->next;
            }
            else {
                l2=l2->next;
            }
        }
        return head;
    }
};

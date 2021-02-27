
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *cur, *pre, *nex;
        cur = head;
        pre = NULL;

        while(cur != NULL){
        	nex = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = nex;
        }
        return pre;
    }
};
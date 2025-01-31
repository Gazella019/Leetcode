


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head, *cur;
        head = new ListNode(-1);
        cur = head;

        while(l1 != NULL || l2 != NULL){
        	if(l1 == NULL){
        		cur->next = l2;
        		break;
        	}
        	if(l2 == NULL){
        		cur->next = l1;
        		break;
        	}
        	if(l1->val <= l2->val){
        		cur->next = l1;
        		l1 = l1->next;
        	}
        	else if(l1->val > l2->val){
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur = cur->next;
        }
        return head->next;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    	if(l1 == NULL)
    		return l2;
    	if(l2 == NULL)
    		return l1;

    	if(l1->val <= l2->val){
    		l1->next = mergeTwoLists(l1->next, l2);
    		return l1;
    	}

    	else if(l1->val > l2->val){
    		l2->next = mergeTwoLists(l1, l2->next);
    		return l2;
    	}
    	return l1;
    }
};
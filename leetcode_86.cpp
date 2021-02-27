



class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        	
        ListNode *cur, *s1, *s2, *h1, *h2;
        s1 = new ListNode(0);
        s2 = new ListNode(0);

        cur = head;
        h1 = s1;
        h2 = s2;

        while(cur != NULL){
        	cout << cur->val << " ";
        	if(cur->val >= x){
        		s2->next = cur;
        		s2 = s2->next;
        	}
        	else{
        		s1->next = cur;
        		s1 = s1->next;
        	}
        	cur = cur->next;
        }
        s2->next = NULL;
        if(h1->next == NULL)
        	return h2->next;

        s1->next = h2->next;
        return h1->next;
    }
};




class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return NULL;
        ListNode *odd, *even, *evenHead;
        odd = head, even = head->next, evenHead = even;

        while(even != NULL && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

    	if(head == NULL)
    		return NULL;
    	
        ListNode *even, *odd, *now, *head2; 
        int length = 1;
        odd = head;
        even = head ->next;
        if(even == NULL){
        	return head;
        }
        head2 = even;
        now = even->next;

        while(now != NULL){

        	if(length%2 == 1){
        		odd->next = now;
        		odd = odd->next;
        	}
        	else if(length%2 == 0){
        		even->next = now;
        		even = even->next;
        	}
        	length = length + 1;
        	now = now->next;
        }

       	even->next = NULL;
       	odd->next = head2;
       	return head;
    }
};
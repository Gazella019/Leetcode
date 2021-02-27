




class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *cur, *pre, *after, *tail, *nHead;
        int count = 1;
        cur = head;
        while(cur != NULL){
            if(count == m){
                nHead = pre;
                tail = cur;
                while(count <= n){
                    after = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = after;
                    count++;
                }
                if(nHead == NULL)
                    head = pre;
                else
                    nHead->next = pre;
                tail->next = cur;
                break;
            }
            pre = cur;
            cur = cur->next;
            count ++;
        }

        return head;
    }
};


 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode *now, *end, *pre, *start, *next;
        now = head;
        pre = NULL;

        if(m == n)
        	return head;

        while(now != NULL){
        	if(count == m){
        		start = pre;
        		end = now;
        		pre = now;
        		now = now->next;
        		next = now->next;
        		count++;
        		while(count <= n){
        			now->next = pre;
        			pre = now;
        			now = next;
        			if(next != NULL)
						next = now->next;
        			count++;
        		}
        		end->next = now;
        		if(m != 1)
        			start->next = pre;
        		else
        			head = pre;
        		break;
        	}
        	pre = now;
        	now = now->next;
        	count ++;
        }

        return head;
    }
};



class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        if(head == NULL)
        	return NULL;
        ListNode *now, *end, *p, *unSorted;
        int count, sortedNum = 1;
        unSorted = head->next;
        end = head;
        
        while(unSorted != NULL){
        	count = 0;
        	now = head;
        	p = NULL;
        	// 從頭開始 search 在哪裡要 insert
        	while(count <= sortedNum){

        		// 最後一個 node insert
        		if(count == sortedNum){
        			end = unSorted;
        			break;
        		}
        		// 不用 insert
        		else if(unSorted->val > now->val){
        			count = count + 1;
        			p = now;
        			now = now->next;
        		}
        		// 執行 insertion
        		else{
        			// 要 insert的值是第一個
        			if(count == 0){
        				end->next = unSorted->next;
        				unSorted->next = now;
        				head = unSorted;
        			}
        			// 在中間 insert
        			else{
        				end->next = unSorted->next;
        				unSorted->next = now;
        				p->next = unSorted;
        			}
        			break;
        		}
        	}
        	sortedNum = sortedNum + 1;
        	unSorted = end->next;
        } 
        return head;
    }
};
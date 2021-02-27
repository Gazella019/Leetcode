

// Runtime: 8 ms, faster than 97.84% of C++
// Memory Usage: 9.6 MB, less than 100.00% of C++

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode *fast, *slow;
    	fast = head;
    	slow = head;

    	while(fast != NULL){

    		fast = fast->next;
    		if(fast == NULL)
    			return NULL;
    		fast = fast->next;
    		if(fast == NULL)
    			return NULL;
    		slow = slow->next;
    		if(slow == fast){
    			fast = head;
    			while(fast != slow){
    				fast = fast->next;
    				slow = slow->next;
    			}
    			return fast;
    		}
    	}
    	return NULL;
    }
};
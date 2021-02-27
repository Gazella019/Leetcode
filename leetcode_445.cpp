

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	
    	int num, carry = 0;
    	stack<int> st1;
    	stack<int> st2;
    	ListNode *prev, *node;

    	while(l1 != NULL){
    		st1.push(l1->val);
    		l1 = l1->next;
    	}
    	while(l2 != NULL){
    		st2.push(l2->val);
    		l2 = l2->next;
    	}

    	while(true){
    		if(st1.size() == 0 && st2.size() == 0)
    			break;
    		num = carry;
    		if(st1.size() != 0){
    			num += st1.top();
    			st1.pop();
    		}
    		if(st2.size() != 0){
    			num += st2.top();
    			st2.pop();
    		}
    		if(num >= 10){
    			num = num - 10;
    			carry = 1;
    		}
    		else
    			carry = 0;
    		ListNode* node = new ListNode(num);
    		node->next = prev;
    		prev = node;
    		
    	}
    	if(carry == 1){
    		ListNode* node = new ListNode(1);
    		node->next = prev;
    		prev = node;
     	}
    	return prev;
    }
};
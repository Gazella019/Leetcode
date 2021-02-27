




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    	ListNode* now;
    	now = head;
    	int count = 0, i;
    	if(head == NULL)
    		return NULL;

    	while(now != NULL){
    		count = count + 1;
    		now = now->next;
    	}

 		now = head;
 		cout << (count/2) + 1;
    	for(i=1;i<(count/2)+1;i++){
    		now = now->next;
    	}    

    	return now;
    }
};
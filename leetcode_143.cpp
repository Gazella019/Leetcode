




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
    	if(head == NULL)
    		return;
        ListNode *now, *p, *temp, *q;
        now = head;
        q = now->next;

	    while(now->next != NULL){
	       	p = now;
	        temp = now->next;
	        while(temp != NULL && temp->next != NULL){
	        	p = p->next;
	        	temp = temp->next;
	        }
	        p->next = NULL;
	        temp->next = now->next;
	        now->next = temp;
	        now = temp->next;
	        if(now == NULL)
	        	break;
	        q = now->next;
	    }
    }
};




class Solution {
public:
    void reorderList(ListNode* head) {
    	vector<int> v;
    	ListNode *now = head;
    	int i, temp;
    	while(now != NULL){
    		v.push_back(now->val);
    		now = now->next;
    	}
    	int l ,r;
    	l = 0;
    	r = v.size()-1;
    	
		while(now!=NULL){
			now->val = v[i];
			now = now->next;
			i++;
		}

    }
};
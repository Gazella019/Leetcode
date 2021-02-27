


// Runtime: 16 ms, faster than 96.55% of C++ 
// Memory Usage: 9.7 MB, less than 100.00% of C++

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL)
    		return NULL;
    	ListNode *now, *pre, *after, *start, *end, *newHead;
    	int i, j, length = 0, count = 0, times;
    	end = NULL;
    	now = head;
    	while(now != NULL){
    		count ++;
    		now = now->next;
    	}
    	if(k > count)
    		return head;
    	times = count / k;
  		pre = NULL;
  		now = head;
  		start = head;
  		after = now->next;
  		for(i=1;i<=times;i++){
  			pre = NULL;
  			for(j=1;j<=k;j++){
  				now->next = pre;
  				pre = now;
  				now = after;
  				if(now != NULL)
  					after = now->next;
  			}
  			if(i == 1){
  				start->next = now;
  				newHead = pre;
  				end = start;
  				start = now;
  			}
  			else{
  				start->next = now;
  				end->next = pre;
  				end = start;
  				start = now;
  			} 
  		}
        return newHead;
    }
};



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    	ListNode *now, *pre, *nextt, *start, *newHead, *end;
    	int i, j, length = 0, count = 0, times;
    	end = NULL;
    	now = head;
    	while(now != NULL){
    		count ++;
    		now = now->next;
    	}
    	times = count / k;
    	pre = NULL;
    	now = head;
    	start = head;
    	nextt = now->next;
    	for(j=1;j<=times;j++){
    		pre = NULL;
	    	for(i=1;i<=k;i++){
	    		//cout << j << " " << i << endl;
	    		//cout << now->val;
	    		now->next = pre;
	    		pre = now;
	    		now = nextt;
	    		if(now != NULL)
	    			nextt = now->next;
	    	}
	    	start->next = now;
	    	if(end == NULL){
	    		end = start;
	    		newHead = pre;
	    	}
	    	else{
                end->next = pre;
	    		end = start;
	    		start = now;
	    	}
	    }
        return newHead;
    }
};
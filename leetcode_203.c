
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
   	int val;
    struct ListNode *next;
};
 

struct ListNode* removeElements(struct ListNode* head, int val){

	struct ListNode *now, *p, *h;
	h = head;
	now = head;
    p = head;/////
	while(1){

		if(now == NULL)
			break;
		if(now->val == val){

			//要刪除的在head的位置
			if(now == h){
				h = now->next;
				now = now->next;
				p = now;
			}

			else{
				p->next = now->next;
				free(now);
				now = p->next;
				if(now == NULL)
					break;
			}

		}
		else{
			p = now;
			now = now->next;
		}

	}
    return h;
}

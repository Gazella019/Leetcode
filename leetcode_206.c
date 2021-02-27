#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){

	struct ListNode *previous, *after, *now;
	if(head == NULL)
		return NULL;

	now = head;
	after = head->next;
	while(1){

		if(after == NULL){
			head->next = NULL;
			head = now;
			break;
		}

		previous = now;
		now = after;
		after = now->next;
		now->next = previous;

	}

    return now;
}

void main(){

}
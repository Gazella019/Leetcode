




struct ListNode {
   	int val;
    struct ListNode *next;
};


bool hasCycle(struct ListNode *head) {

	if(head == NULL)
		return false;

	struct ListNode *now, *previous, *after;
	bool toHead = false;
	now = head;
	previous = NULL;
	after = head->next;

	while(1){

		// 只有一個node
		if(after == NULL){
			break;
		}
		//printf("%d\n", now->val);
		now->next = previous;
		previous = now;
		now = after;
		after = now->next;

		if(after == NULL){
			if(now == head){
				toHead = true;
			}
			break;
		}
	}
	//printf("is head %d\n", toHead);
    return toHead;
}



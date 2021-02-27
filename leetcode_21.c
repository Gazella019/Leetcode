#include<stdio.h>
#include<stdlib.h>

struct ListNode {
 	    int val;
 		struct ListNode *next;
	};

void printList(struct ListNode* input){

	struct ListNode *now = input;
	while(1){

		if(now != NULL){
			printf("%d",now->val);
			if(now->next == NULL)
				break;
			printf("->");
			now = now->next;
		}
		else{
			break;
		}
	}
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	struct ListNode *t1 = l1;
	struct ListNode *t2 = l2;
	struct ListNode *now = NULL, *header;
	int toogle = 1;
	
	while(1){
		if(t1 == NULL && t2 == NULL){
			return NULL;
		}

		else if(t1 == NULL){
            
            if(now == NULL){
                header = t2;
                break;
            }
			now->next = t2;
			break;
		}
		else if(t2 == NULL){
            if(now == NULL){
                header = t1;
                break;
            }
			now->next = t1;
			break;
		}

		if(t1->val > t2->val){
			if(toogle == 1){
				now = t2;
				t2 = t2->next;
				header = now;
				toogle = 0;
			}
			else{
				now->next = t2;
				now = now->next;
				t2 = t2->next;
			}
		}
		else if (t1->val <= t2->val){
			if(toogle == 1){
				now = t1;
				t1 = t1->next;
				header = now;
				toogle = 0;
			}
			else{
				now->next = t1;
				now = now->next;
				t1 = t1->next;
			}
		}

	}
	return header;
}



void main(){

	// Build the test linked list
	struct ListNode *head, *l1, *l2, *result;
	struct ListNode *p= malloc(sizeof(*p));

	l1 = p;
	p->val = 1;
	p->next = malloc(sizeof(*p));
	p = p->next;
	p->val = 2;
	p->next = malloc(sizeof(*p));
	p = p->next;
	p->val = 4;
	p->next = NULL;

	struct ListNode *q= malloc(sizeof(*q));

	l2 = q;
	q->val = 1;
	q->next = malloc(sizeof(*q));
	q = q->next;
	q->val = 3;
	q->next = malloc(sizeof(*q));
	q = q->next;
	q->val = 4;
	q->next = NULL;

	//printList(l1);
	//printList(l2);
	
	result = mergeTwoLists(l1, l2);
	printList(result);
	
	
}

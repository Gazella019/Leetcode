




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
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
        	while(count <= sortedNum){

        		if(count == sortedNum){
        			end = unSorted;
        			break;
        		}
        		else if(unSorted->val > now->val){
        			count = count + 1;
        			p = now;
        			now = now->next;
        		}
        		// 執行 insertion
        		else{
        			if(count == 0){
        				end->next = unSorted->next;
        				unSorted->next = now;
        				head = unSorted;
        			}
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
        	//cout << "unSorted is " << unSorted->val << endl;
        } 
        return head;
    }
};

//[-1,5,3,4,0]



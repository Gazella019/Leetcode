


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int r, cnt = 0, group;
        bool isHead = true;
        vector<ListNode*> res;
        ListNode *cur, *next;

        cur = root;

        while(cur != NULL){
        	cur = cur->next;
        	cnt ++;
        }
        group = cnt/k;
        r = cnt%k;
        cur = root, cnt = 0;
        while(cur != NULL){
        	cnt ++;
        	if(isHead == true){
        		isHead = false;
        		res.push_back(cur);
        	}
        	if(r <= 0 && cnt == group){
        		cnt = 0;
        		next = cur->next;
        		cur->next = NULL;
        		cur = next;
        		isHead = true;
        	}
        	else if(r > 0 && cnt == 1+group){
        		cnt = 0;
        		r --;
        		next = cur->next;
        		cur->next = NULL;
        		cur = next;
        		isHead = true;
        	}
        	else{
        		cur = cur->next;
        	}
        }
        while(res.size() < k){
        	res.push_back(NULL);
        }
        return res;
    }
};
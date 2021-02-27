


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int i, m = 1, res = 0;
        vector<int> v;

        while(head != NULL){
        	v.push_back(head->val);
        	head = head->next;
        }

        for(i=v.size()-1;i>=0;i--){
        	res = res + (m * v[i]);
        	m = m << 1;
        }

        return res;
    }
};
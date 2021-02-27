


class Solution {
public:
	bool res = false;
    bool isSubPath(ListNode* head, TreeNode* root){
        
        traversal(head, root);
        return res;
    }

    void traversal(ListNode* head, TreeNode* root){
    	if(root == NULL || res == true)
    		return;
    	find(head, root);
    	traversal(head, root->left);
    	traversal(head, root->right);
    }

    void find(ListNode * head, TreeNode* root){

    	if(head == NULL){
    		res = true;
    		return;
    	}
    	if(root == NULL)
    		return;

    	if(head->val == root->val){
    		find(head->next, root->left);
    		find(head->next, root->right);
    	}
    	
    }
};
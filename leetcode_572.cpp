


class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(isSame(s, t))
            return true;
        if(s == NULL)
            return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSame(TreeNode* s, TreeNode* t){
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        if(s->val == t->val){
            return isSame(s->left, t->left) && isSame(s->right, t->right);
        }
        return false;
    }
};



class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	bool tf = false;
        traversal(s, t, &tf);
        return tf;
    }

    void traversal(TreeNode* s, TreeNode* t, bool* tf){
    	if(s == NULL || t == NULL)
    		return;
    	if(s->val == t->val){
    		if(*tf == false)
    			*tf = isSame(s, t);
    	}
    	traversal(s->left, t, tf);
    	traversal(s->right, t, tf);
    }

    bool isSame(TreeNode* s, TreeNode* t){
    	if(s == NULL && t == NULL)
    		return true;
    	else if(s == NULL || t == NULL)
    		return false;

    	if(s->val != t->val)
    		return false;
    	else{
    		bool r, l;
    		l = isSame(s->left, t->left);
    		r = isSame(s->right, t->right);
    		if(l && r)
    			return true;
    		return false;
    	}
    }
};
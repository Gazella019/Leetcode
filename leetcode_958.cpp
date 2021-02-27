


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        TreeNode *cur;
        q.push(root);

        while(q.size() != 0){
            cur = q.front();
            if(cur == NULL && q.size() > 1)
                return false;
            if(cur != NULL && (cur->left != NULL || cur->right != NULL)){
                q.push(cur->left);
                q.push(cur->right);
            }
            q.pop();
        }

        return true;
    }
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
    	if(root == NULL)
    		return true;
    	TreeNode* node;
    	queue<TreeNode*> q;
    	vector<int> v;
    	bool tf = true;
    	int i, count = 0;

    	q.push(root);
    	while(q.size() != 0 && tf){
    		node = q.front();
    		if(node != NULL){
    			q.push(node->left);
	    		q.push(node->right);
	    		v.push_back(1);
	    	}
	    	else
	    		v.push_back(0);
	    	q.pop();
    	}

    	for(i=1;i<v.size();i++){
    		if(v[i] != v[i-1])
    			count = count + 1;
    	}
    	if(count == 1)
    		tf = true;
    	else
    		tf = false;
    	return tf; 
    }
};
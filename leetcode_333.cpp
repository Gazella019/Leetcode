


// O(N)
class Solution {
public:
	int res = 1;
	int largestBSTSubtree(TreeNode* root) {
        
        if(root == NULL)
        	return 0;
        vector<int> v;
        traversal(root, v);
        return res;
    }

    void traversal(TreeNode* root, vector<int>& v){

    	if(root == NULL){
    		return;
    	}
    	bool isBST = true;
    	int i, cnt = 1, prev;
    	prev = v.size();
    	traversal(root->left, v);
    	v.push_back(root->val);
    	traversal(root->right, v);

    	for(i=prev+1;i<v.size();i++){
    		if(v[i] <= v[i-1]){
    			isBST = false;
    			break;
    		}
    		cnt ++;
    	}
    	cout << "root:" << root->val << " isBST:" << isBST << " cnt:" << cnt << endl;
    	if(isBST)	res = max(res, cnt);
    }
};

class Solution {
public:
	int res = 1, cnt = 0;

    int largestBSTSubtree(TreeNode* root) {
        
        if(root == NULL)
        	return 0;
        traversal(root);
        
        return res;
    }

    void traversal(TreeNode* root){
    	if(root == NULL)
    		return;
    	if(isBST(root, INT_MAX, INT_MIN))
    		res = max(res, nums(root));
    	traversal(root->left);
    	traversal(root->right);
    }

    bool isBST(TreeNode* root, int upper, int lower){

    	if(root == NULL)
    		return true;
    	if(root->val < upper && root->val > lower)
    		return isBST(root->left, root->val, lower) && isBST(root->right, upper, root->val);
    	return false;
    }

    int nums(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return nums(root->left) + nums(root->right) + 1;
    }
};


class Solution {
public:
	int res = 1, cnt = 0;

    int largestBSTSubtree(TreeNode* root) {
        
        if(root == NULL)
        	return 0;
        vector<int> v;
        v = dfs(root, INT_MAX, INT_MIN);
        return res;
    }

    vector<int> dfs(TreeNode* root, int upper, int lower){

    	if(root == NULL){
    		return{1, 0};
    	}
    	int isBST, total;
    	vector<int> l;
    	vector<int> r;
    	l = dfs(root->left, root->val, lower);
    	r = dfs(root->right, upper, root->val);
    	total = l[1] + r[1] + 1;
    	if(l[0] && r[0])
    		res = max(res, total);
    	isBST = l[0] && r[0] && root->val < upper && root->val > lower;
    	cout << root->val << " isBST=" << isBST << " total=" << total << endl;
    	return{isBST, total};
    }
};
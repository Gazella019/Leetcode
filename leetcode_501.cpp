





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// RDL solution
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int max = 0, count = 0, previous = 888;
        vector<int> res;
        inorder(root, &previous, &max, &count);
        cout << max;
        return res;
    }

    void inorder(TreeNode* root, int *previous, int *max, int *count){
    	if(root == NULL)
    		return;

    	inorder(root->left, previous, max, count);
    	//cout << "node " << root->val << " previous " << *previous << endl;
    	if(root->val == *previous){
    		*count = *count + 1;
    		if(*count > *max)
    			*max = *count;
 		}
 		else{
 			*count = 1;
 			if(1 > *max)
 				*max = 1;
 		}
 		*previous = root->val;
 		inorder(root->right, previous, max, count);

    }

    void ans(TreeNode* root, vector<int>& res, int max, int* count, int p){
    	if(root == NULL)
    		return;
    	ans(root, re)
    }
};



class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int max = 0, count = 0;
        vector<int> res;
        map<int, int> hash;
        traversal(root, &max, hash);
        for(auto p : hash){
        	if(p.second == max)
        		res.push_back(p.first);
        }
        return res;
    }

    void traversal(TreeNode* root, int* max, map<int, int>& hash){
    	if(root == NULL)
    		return;
    	if(hash.find(root->val) == hash.end()){
    		hash[root->val] = 1;
    		if(1 > *max)
    			*max = 1;
    	}
    	else{
    		hash[root->val] ++;
    		if(hash[root->val] > *max)
    			*max = hash[root->val];
    	}

    	traversal(root->left, max, hash);
    	traversal(root->right, max, hash);

    }
};



class Solution {
public:
	unordered_map<int, vector<int>> hash;
	int minVal = INT_MAX, maxVal = 0;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
        	return {};
        int i, index, sz;
        queue<TreeNode*> q;
        queue<int> qq;
        TreeNode *cur;
        q.push(root);
        qq.push(0);
        while(q.size() != 0){
        	sz = q.size();
        	for(i=1;i<=sz;i++){
        		cur = q.front();
        		index = qq.front();
        		q.pop(), qq.pop();
        		minVal = min(minVal, index);
        		maxVal = max(maxVal, index);
        		hash[index].push_back(cur->val);
        		if(cur->left != NULL){
        			q.push(cur->left);
        			qq.push(index-1);
        		}
        		if(cur->right != NULL){
        			q.push(cur->right);
        			qq.push(index+1);
        		}
        	}
        }
        vector<vector<int>> res(maxVal-minVal+1);
        for(auto& it: hash){
        	res[it.first-minVal] = it.second;
        }

        return res;
    }
};
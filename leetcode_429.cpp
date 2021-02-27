





class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
    	vector<vector<int>> res;
    	if(root == NULL)
    		return res;
    	traversal(root, res, 0);
    	return res;
    }

    void traversal(Node* root, vector<vector<int>>& res, int level){
    	if(res.size() == level)
    		res.push_back({});
    	res[level].push_back(root->val);
    	for(int i=0;i<root->children.size();i++){
    		traversal(root->children[i], res, level+1);
    	}
    }
};





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
    vector<int> preorder(Node* root) {
        vector<int> v;
        traversal(v, root);
        return v;
    }

    void traversal(vector<int>& v, Node* root){
    	if(root == NULL)
    		return;
    	v.push_back(root->val);
    	for(int i=0;i<root->children.size();i++){
    		traversal(v, root->children[i]);
    	}
    }
};
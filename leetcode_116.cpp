

// Runtime: 52 ms, faster than 90.10% of C++ 
// Memory Usage: 27 MB, less than 100.00% of C++

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:

    Node* connect(Node* root) {
        vector<Node*> table;
        traveral(root, table, 0);
        return root;
    }

    void traveral(Node* root, vector<Node*>& table, int level){
    	if(root == NULL)
    		return;
    	if(table.size() <= level)
    		table.push_back(root);
    	else{
    		table[level]->next = root;
    		table[level] = root;
    	}
    	traveral(root->left, table, level+1);
    	traveral(root->right, table, level+1);
    }
};
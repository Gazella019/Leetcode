

struct Node{

	struct Node* prev;
	struct Node* next;

	int value;

}

class LRUCache {
public:

	unordered_map<int, Node*> hash;
	
	int cur = 0, nums;

    LRUCache(int capacity) {
    	
    }
    
    int get(int key) {
    	if(hash.find(key) == hash.end())
    }
    
    void put(int key, int value) {

    	
    }

    void del(*Node n){
    	*Node 
    }
};



//


class LRUCache {
public:

	unordered_map<int, int> hash;
	queue<int> q;
	int cur = 0, nums;

    LRUCache(int capacity) {
    	nums = capacity;
    }
    
    int get(int key) {
    	if(hash.find(key) == hash.end())
    		return -1;
        int i, sz = q.size();
        for(i=1;i<=sz;i++){
        	if(q.front() != key)
        		q.push(q.front());
        	q.pop();
        }
        q.push(key);
        
        return hash[key];
    }
    
    void put(int key, int value) {

    	if(hash.find(key) != hash.end()){
    		int sz = q.size();
    		for(int i=1;i<=sz;i++){
    			if(q.front() != key)
    				q.push(q.front());
    			q.pop();
    		}
    		q.push(key);
    	}
    	else{
    		if(q.size() == nums){
    			hash.erase(q.front());
    			q.pop();
    		}
        	q.push(key);
    	}
    	hash[key] = value;
    }
};

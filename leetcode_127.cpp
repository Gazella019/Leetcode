


// BFS 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i, j, count = 0, step = 1, newcount;
        bool tf = false;
        string word;
        queue<string> q;
        vector<int> used(wordList.size(), 0);
        step ++;
        for(i=0;i<wordList.size();i++){
        	if(canTransform(beginWord, wordList[i])){
        		if(wordList[i] == endWord)
        			return step;
        		q.push(wordList[i]);
        		used[i] = 1;
        		count++;
        	}
        	if(wordList[i] == endWord)
        		tf = true;
        }
        if(tf == false)
        	return 0;
        while(q.size() != 0){
        	step ++;
        	newcount = 0;
        	for(i=1;i<=count;i++){
	        	word = q.front();
	        	for(j=0;j<wordList.size();j++){
	        		if(used[j] == 0){
	        			if(canTransform(word, wordList[j])){
	        				if(wordList[j] == endWord)
	        					return step;
	        				q.push(wordList[j]);
	        				used[j] = 1;
	        				newcount ++;
	        			}
	        		}
	        	}
	        	q.pop();
        	}
        	count = newcount;
        }
        return 0;
    }


    bool canTransform(string origin, string target){
    	int diff = 0;
    	for(int i=0;i<origin.size();i++){
    		if(origin[i] != target[i])
    			diff++;
    	}
    	if(diff == 1)
    		return true;
    	return false;
    }
};
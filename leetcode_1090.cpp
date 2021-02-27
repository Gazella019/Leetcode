


class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        int i, cur, res = 0;
        bool notFound;
        vector<vector<int>> table(values.size(), vector<int>(2, 0));
        unordered_map<int, int> usedNum;

        for(i=0;i<values.size();i++){
        	table[i][0] = values[i];
        	table[i][1] = labels[i];
        	usedNum[labels[i]] = 0;
        }
        sort(table.begin(), table.end(), [](vector<int> &a, vector<int> &b){
        	return a[0] < b[0];
        });
        cur = values.size()-1;
        for(i=1;i<=num_wanted;i++){
        	notFound = true;
        	while(notFound == true && cur >= 0){
        		if(usedNum[table[cur][1]] < use_limit){
        			usedNum[table[cur][1]] ++;
        			res += table[cur][0];
        			notFound = false; 
        		}
        		cur --;
        	}
        }

        return res;
    }
};



class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        int i, j, mx, res = 0;
        unordered_map<int, vector<int>> hash;
        unordered_map<int, vector<int>> used;
        unordered_map<int, int> table;
        priority_queue<int> pq;
        bool notFound;
        for(i=0;i<values.size();i++){
        	hash[values[i]].push_back(labels[i]);
        	used[values[i]].push_back(0);
        	table[labels[i]] = 0;
        	pq.push(values[i]);
        }

        for(i=1;i<=num_wanted;i++){
        	notFound = true;
        	while(notFound && pq.size() > 0){
	        	mx = pq.top();
	        	pq.pop();
	        	for(j=0;j<hash[mx].size();j++){
	        		if(table[hash[mx][j]] < use_limit && used[mx][j] == 0){
	        			res = res + mx;
	        			table[hash[mx][j]] += 1;
	        			used[mx][j] = 1;
	        			notFound = false;
	        			break;
	        		}
	        	}
	        }
        }
        return res;
    }
};
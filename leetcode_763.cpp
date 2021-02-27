



class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int start, end;
        vector<int> v(26, -1);
        vector<int> res;

        for(int i=0;i<S.size();i++){
            v[S[i]-'a'] = i;
        }
        start = 0, end = -1;
        for(int i=0;i<S.size();i++){
            end = max(end, v[S[i]-'a']);
            if(end == i){
                res.push_back(i-start+1);
                start = i + 1;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int i, count, dist;
        vector<int> res;
        vector<int> table(26, -1);

        for(i=0;i<S.size();i++){
        	table[S[i]-'a'] = i;
        }

        for(i=0;i<S.size();i++){
        	dist = table[S[i]-'a'];
        	count = 0;
        	while(i <= dist){
        		if(table[S[i]-'a'] > dist)
        			dist = table[S[i]-'a'];
        		i++;
        		count++;
        	}
        	i--;
        	res.push_back(count);
        }
        return res;
    }
};


// merge interval

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int i;
        vector<vector<int>> table(26, vector<int>(2, -1));
        vector<vector<int>> interval;
        vector<vector<int>> merged;
        vector<int> temp;
        vector<int> res;

        for(i=0;i<S.size();i++){

        	if(table[S[i]-'a'][0] == -1)
        		table[S[i]-'a'][0] = i;
        	else
        		table[S[i]-'a'][1] = i;
        }

        for(i=0;i<26;i++){
        	if(table[i][0] != -1){
        		if(table[i][1] == -1)
        			table[i][1] = table[i][0];
        		interval.push_back(table[i]);
        	}
        }

        sort(interval.begin(), interval.end());
        temp = interval[0];
        for(i=1;i<interval.size();i++){
        	if(interval[i][0] < temp[1]){
        		temp[0] = min(temp[0], interval[i][0]);
        		temp[1] = max(temp[1], interval[i][1]);
        	}
        	else{
        		res.push_back(temp[1]-temp[0]+1);
        		temp = interval[i];
        	}
        }
        res.push_back(temp[1]-temp[0]+1);
        return res;
    }
};




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		
		int i;
		stack<int> st;
		vector<int> res(T.size(), 0);

		for(i=0;i<T.size();i++){

			while(st.size() != 0 && T[st.top()] < T[i]){
				res[st.top()] = i-st.top();
				st.pop();
			}
			st.push(i);
		}
		
		return res;
    }
};



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		
		int i, j, temp;
		vector<int> res(T.size(), 0);
		unordered_map<int, vector<int>> hash;

		for(i=0;i<T.size();i++){
			for(temp=T[i]-1;temp>=30;temp--){
				for(j=0;j<hash[temp].size();j++){
					res[hash[temp][j]] = i-hash[temp][j];
				}
				hash[temp].clear(); 
			}
			hash[T[i]].push_back(i);
		}
		return res;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		
		int i, j, temp;
		stack<int> st;
		vector<int> res(T.size(), 0);
		unordered_map<int, int> hash;

		for(i=0;i<T.size();i++){

			while(st.size() != 0){
				if(hash[st.top()] >= T[i])
					break;
				res[st.top()] = i-st.top();
				st.pop();
			}
			hash[i] = T[i];
			st.push(i);
		}
		return res;
    }
};
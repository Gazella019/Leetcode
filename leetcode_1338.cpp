


class Solution {
public:
    int minSetSize(vector<int>& arr) {

        int i, half, res, n;
        unordered_map<int, int> hash;
        vector<int> v;
        n = arr.size();
        half = n / 2;


        for(i=0;i<arr.size();i++){
        	if(hash[arr[i]] == 0)
        		hash[arr[i]] = 1;
        	else
        		hash[arr[i]] ++;
        }

        for(auto &a:hash){
        	v.push_back(a.second);
        }

        sort(v.begin(), v.end());

        for(i=0;i<v.size();i++){
        	cout << v[i] << " ";
        }

        for(i=v.size()-1;i>=0;i--){
        	res ++;
        	n = n-v[i];
        	if(n <= half){
        		return res;
        	}
        }
        return 0;
    }
};
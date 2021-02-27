


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		
		vector<vector<string>> res(searchWord.size());
		int i, j, cur = 0;        
        sort(products.begin(), products.end());

        for(i=0;i<searchWord.size();i++){
        	for(j=cur;j<products.size();j++){
        		if(i < products[j].size() && products[j].substr(0, i+1) == searchWord.substr(0, i+1)){
        			cur = j;
        			break;
        		}
        	}
        	if(j == products.size())
        		continue;
        	for(j=cur;j<products.size();j++){
        		if(j == cur+3)
        			break;
        		if(i < products[j].size() && products[j].substr(0, i+1) == searchWord.substr(0, i+1))
        			res[i].push_back(products[j]);
        		else
        			break;
        	}
        }

        return res;
    }
};
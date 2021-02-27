


class Solution {
public:
    int candy(vector<int>& ratings) {
        
    	int i, sum = 0;
    	bool modifyed = true;
    	vector<int> v(ratings.size(), 1);

    	while(modifyed == true){
    		modifyed = false;
    		for(i=0;i<v.size();i++){
    			if(i != 0 && ratings[i]<ratings[i-1] && v[i]>=v[i-1]){
    				v[i-1] = v[i] + 1;
    				modifyed = true;
    			}
    			if(i != ratings.size()-1 && ratings[i]<ratings[i+1] && v[i]>=v[i+1]){
    				v[i+1] = v[i] + 1;
    				modifyed = true;
    			}
    		}
    	}

    	for(i=0;i<v.size();i++){
    		sum = sum + v[i];
    		cout << v[i] << " "; 
    	}

    	return sum;
    }
};
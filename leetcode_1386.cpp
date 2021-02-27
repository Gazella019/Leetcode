




class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int i, j, res = 0, row, pos;
        bool used;
        unordered_map<int, vector<int>> hash;

        for(i=0;i<reservedSeats.size();i++){
        	row = reservedSeats[i][0];
        	pos = reservedSeats[i][1];
        	if(hash.find(row) == hash.end()){
        		hash[row] = vector<int>(11, 1);
        	}
        	hash[row][pos] = 0;
        }

        res = res + (n-hash.size()) * 2;

        for(auto& it: hash){
        	used = false;
        	if(it.second[2] && it.second[3] && it.second[4] && it.second[5]){
        		res += 1;
        		used = true;
        	}
        	if(it.second[6] && it.second[7] && it.second[8] && it.second[9]){
        		res += 1;
        		used = true;
        	}
        	if(used == false && it.second[4] && it.second[5] && it.second[6] && it.second[7])
        		res += 1;
        }

        return res;
    }
};
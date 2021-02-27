


class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
    	if(S.size() == 0)
    		return "";
        char now = S[0];
        int i, diff, sum = 0;

        for(i=shifts.size()-1;i>=0;i--){
        	if(shifts[i] > 26){
        		shifts[i] = shifts[i] % 26
        	}
        	sum = sum + shifts[i];
        	shifts[i] = sum;
        }
        for(i=0;i<shifts.size();i++){
        	S[i] = shiftChar(S[i], shifts[i]);
        }
        return S;
    }

    char shiftChar(char c, int num){
    	int temp = c - 'a';
    	temp = temp + num;
    	while(temp >= 26){
    		temp = temp - 26;
    	}
    	return temp + 'a';
    }

};
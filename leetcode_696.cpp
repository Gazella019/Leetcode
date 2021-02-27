class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero, one, i, j, k, diff, count = 0;

        for(i=0;i<s.size();i++){
        	for(j=i+1;j<s.size();j++){
        		one = 0;
        		zero = 0;
        		diff = 0;
        		for(k=i;k<=j;k++){
        			if(k!=i && s[k] != s[k-1]){
        				diff++;
        				if(diff >= 2)
        					break;
        			}
        			if(s[k] == '1')
        				one ++;
        			if(s[k] == '0')
        				zero ++;
        		}
        		//cout << "diff : " << diff << " zero: " << zero << " one: " << one << endl;
        		cout << "i :" << i << "j :" << j << endl;
        		if(diff <= 1 && one == zero)
        			count = count + 1;
        	}
        }
        return count;
    }
};
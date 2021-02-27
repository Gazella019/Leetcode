



class Solution {
public:
    int numSteps(string s) {
        
        int i, cnt = 0, carry;
        vector<int> v;
        for(i=s.size()-1;i>=0;i--){
        	v.push_back(s[i]-'0');
        }


        while(true){
        	if(v.size() == 1)
        		break;
        	cnt ++;
        	if(v[0] == 0){
        		for(i=0;i<v.size()-1;i++){
        			v[i] = v[i+1]; 
        		}
        		v.pop_back();
        	}
        	else{

        		carry = 1;
        		for(i=0;i<v.size();i++){
        			if(v[i] == 0){
        				if(carry == 1)
        					v[i] = 1;
        				carry = 0;
        			}
        			else{
        				if(carry == 1){
        					v[i] = 0;
        					carry = 1;
        				}
        			}
        		}
        		if(carry == 1)
        			v.push_back(1);
        	}
        }
        return cnt;
    }
};
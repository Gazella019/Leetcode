

class Solution {
public:
    int calculate(string s) {
        
        int i, j, sum = 0, num, res = 0, sign = 1;
    	vector<int> v;

    	for(i=0;i<s.size();i++){

    		while(s[i] >= '0' && s[i] <= '9'){
    			sum = (sum * 10) + (s[i]-'0');
    			i++;
    		}
    		sum = sign * sum;
    		sign = 1;
    		if(s[i] == '*'){
    			num = 0;
    			i ++;
    			while(true){
    				if(s[i] >= '0' && s[i] <= '9')
    					num = (num * 10) + (s[i]-'0');
    				if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i >= s.size())
    					break;
    				i++;
    			}
    			i --;
    			sum = sum * num;
    		}
    		else if(s[i] == '/'){
    			num = 0;
    			i ++;
    			while(true){
    				if(s[i] >= '0' && s[i] <= '9')
    					num = (num * 10) + (s[i]-'0');
    				if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i >= s.size())
    					break;
    				i++;
    			}
    			i --;
    			sum = sum / num;
    		}
    		else if(s[i] == '+'){
    			v.push_back(sum);
    			sum = 0;
    		}
    		else if(s[i] == '-'){
    			v.push_back(sum);
    			sign = -1;
    			sum = 0;
    		}
    	}
    	v.push_back(sum);

    	for(i=0;i<v.size();i++){
    		cout << v[i] << " ";
    		res = res + v[i];
    	}
    	return res;
    }
};
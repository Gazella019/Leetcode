



// Version 1
// 沒有考慮雙位數
class Solution {
public:
    string decodeString(string s) {
    	stack<char> stack;
    	string str, temp, chunk="";
    	int i, j, k, num;
    	for(i=0;i<s.size();i++){
    		if(s[i] == ']'){
    			while(1){
    				if(stack.top() == '['){
    					stack.pop();
    					num = stack.top()-48;
    					stack.pop();
    					temp = "";
    					for(j=1;j<=num;j++){
    						temp = temp + chunk;
    					}
    					if(stack.size() >0){
    						if(stack.top()!='['){
    							for(k=0;k<temp.size();k++){
    								stack.push(temp[k]);
    							}
    						}
    						chunk = "";
    						break;
    					}
    					else{
    						chunk = "";
    						break;
    					}
    				}
    				else{
    					chunk = stack.top() + chunk;
    					stack.pop();
    				}
    			}
    		}
    		else{
    			stack.push(s[i]);
    		}

    	}
    	cout << stack.size();
    	if(stack.size() > 0){
    		temp = "";
    		for(i=1;i<=stack.size();i++){
    			temp = stack.top() + temp;
    			stack.pop(); 
    		}
    	}
    	str = str + temp;
    	return str;    
    }
};
// Verion 2 

class Solution {
public:
    string decodeString(string s) {
    	if(s.size() == 0)
    		return "";
    	stack<char> sc;
    	stack<int> num;
    	int i, sum = 0, j, len;
    	string temp, str = "", res;
    	bool addChar= false;	  
    	for(i=0;i<s.size();i++){

    		if(isNumber(s[i])){
    			if(sum>0){
    				sum = sum*10 + (s[i]-'0');
    			}
    			else{
    				sum = s[i] - '0';
    			}
    		}
    		else if(s[i] == '['){
    			num.push(sum);
    			sum = 0;
    			sc.push(s[i]);
    		}
    		else if(s[i] == ']'){
    			temp = "";
    			str = "";
    			while(1){
    				if(sc.top() == '['){
    					for(j=1;j<=num.top();j++){
    						str = str + temp;
    					}
    					num.pop();
    					sc.pop();
    					if(sc.size() == 0){
    						res = res + str;
    						break;
    					}
    					else{
    						for(j=0;j<str.size();j++){
    							sc.push(str[j]);
    						}
    						break;
    					}
    				}
    				temp = sc.top() + temp; 
    				sc.pop();   			
    			}
    		}
    		else{
    			sc.push(s[i]);
    		}
    	}

    	temp = "";
    	len = sc.size(); 
    	if(len > 0){
    		for(j=1;j<=len;j++){
    			temp = sc.top() + temp;
    			sc.pop();
    		}
    		res = res + temp;
    	}
    	return res;
    }

    bool isNumber(char c){
    	if(c>='0' && c<='9')
    		return true;
    	return false;
    }
};
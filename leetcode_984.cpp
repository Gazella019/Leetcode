

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        
        int a, b;
        string res;
        a = A;
        b = B;
        while(a > 0 && b > 0){
            if(a > b){
                res += "aab";
                a --;
            }
            else if(b > a){
                res += "bba";
                b --;
            }
            else
                res += "ab";
            a --, b --;
        }
        while(a > 0){
            res += "a";
            a --;
        }
        while(b > 0){
            res += "b";
            b--;
        }
        return res;
    }
};




class Solution {
public:
    string strWithout3a3b(int A, int B) {
        
        int cur = 0, cm, cl;
        string more, less;
        char l;
        string str;
        if(A > B){
        	more = "a";
        	cm = A;
        	less = "b";
        	cl = B;
        	l = 'b';
        }
        else{
        	more = "b";
        	cm = B;
        	less = "a";
        	cl = A;
        	l = 'a';
        }

        while(cm > 0){
        	str = str + more;
        	cm--;
        	if(cm == 0)
        		break;
        	str = str + more;
        	cm--;
        	if(cl == 0)
        		continue;
        	str = str + less;
        	cl--;
        }

        while(cl != 0 && cur < str.size()){
        	if(str[cur] == l){
        		str.insert(cur, less);
        		cur += 2, cl --;
        	}
        	else
        		cur++;
        }
        while(cl > 0){
        	str = str + less;
        	cl --;
        }
        return str;
    }
};
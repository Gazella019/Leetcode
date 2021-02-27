
// 1072741824
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int res = 0, mul;
        stack<int> mm;
        stack<int> nn;
        if(m == n)
        	return m;
        while(m != 0){
        	if(m%2 == 0)
        		mm.push(0);
        	else
        		mm.push(1);
        	m = m/2;
        }

        while(n != 0){
        	if(n%2 == 0)
        		nn.push(0);
        	else
        		nn.push(1);
        	n = n/2;
        }

        if(nn.size() != mm.size())
        	return 0;
        mul = 1 << (nn.size()-1);
        while(nn.size() != 0){
        	if(nn.top() == mm.top()){
        		if(nn.top() == 1)
        			res += mul;
        		mm.pop(), nn.pop();
        	}
        	else
        		break;
        	mul = mul / 2;
        }
        return res;
    }
};



// sol 1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bool tf;
        int i, j, res = 0, mul = 1;
        for(i=1;i<=31;i++){
            tf = true;
            for(j=m;j<=n;j++){
                if((j & mul) == 0){
                    tf = false;
                    break;
                }
                if(j == INT_MAX)
                    break;
            }
            if(tf == true)
                res += mul;
            mul = mul << 1;
        }
        return res;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;
        if(x == 0)
        	return true;
        vector<int> v;
        int i, length;
        bool tf = true;
        while(x != 0){
        	v.push_back(x % 10);
        	x = x / 10;
        }
        length = v.size();
        for(i=0;i<length/2;i++){
        	if(v[i] != v[length-i-1]){
        		tf = false;
        		break;
        	}
        }
        return tf;
    }
};
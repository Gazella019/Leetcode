

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int i, a = 0, b = 0;
        vector<int> t1(10, 0);
        vector<int> t2(10, 0);
        unordered_map<char, int> hash;

        for(i=0;i<secret.size();i++){
        	if(secret[i] == guess[i])
        		a ++;
        	else{
        		t1[secret[i]-'0'] += 1;
        		t2[guess[i]-'0'] += 1;
        	}
        }
        for(i=0;i<10;i++){
        	b = b + min(t1[i], t2[i]);
        }

        return to_string(a) + 'A' + to_string(b) + 'B';;
    }
};
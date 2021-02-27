


class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> s1(26, 0);
        vector<int> t1(26, 0);
        int i, now = 0, count = 0;

        for(i=0;i<s.size();i++){
        	s1[s[i]-'a'] += 1;
        }

        for(i=0;i<t.size();i++){
        	t1[t[i]-'a'] += 1;
        }

        while(now < 26){
        	if(s1[now] > t1[now]){
        		s1[now] -= 1;
        		count ++;
        		for(i=0;i<26;i++){
        			if(s1[i] < t1[i])
        				s1[i] += 1;
        		}
        	}
        	if(s1[now] <= t1[now]){
        		now ++;
        	}
        }

        return count;
    }
};



class Solution {
public:
    bool wordPattern(string pattern, string str) {
       	

       	int i, j, cur = 0;
       	unordered_map<char, string> hash;
       	unordered_map<string, int> used;
       	string temp;

       	for(i=0;i<pattern.size();i++){
       		for(j=cur;j<str.size();j++){
       			if(str[j] == ' ' || j == str.size()-1){
       				if(j == str.size()-1)
       					temp = str.substr(cur, j-cur+1);
       				else
       					temp = str.substr(cur, j-cur);

       				if(hash.find(pattern[i]) != hash.end()){
       					if(hash[pattern[i]] != temp){
       						return false;
       					}
       				}
       				else{
       					if(used[temp] >= 1)
       						return false;
       					used[temp] = 1;
       					hash[pattern[i]] = temp;
       				}
       				cur = j+1;
       				break;
       			}
       		}
       	}
       	if(j != str.size()-1)
       		return false;
       	return true;
    }
};
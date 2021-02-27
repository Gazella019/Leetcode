



class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    	if(letters.size() == 0)
    		return '0';
        int i;
        for(i=0;i<letters.size();i++){
        	if(letters[i] > target)
        		return letters[i];
        }
        return letters[0];
    }
};
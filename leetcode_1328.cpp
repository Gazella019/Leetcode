


class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int i, half;
        bool isbreak = false;

        if(palindrome.size() == 1)
        	return "";

        if(palindrome.size() % 2 == 1)
        	half = (palindrome.size() / 2);
        else
        	half = -1;

        for(i=0;i<palindrome.size();i++){
        	if(palindrome[i] != 'a' && i != half){
        		palindrome[i] = 'a';
        		return palindrome;
        	}
        }

        for(i=palindrome.size()-1;i>=0;i--){
        	if(palindrome[i] != 'z' && i != half){
        		palindrome[i] += 1;
        		return palindrome;
        	}
        }

        return "";
    }
};
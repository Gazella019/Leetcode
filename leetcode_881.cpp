

// O(nlogn)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    	if(people.size() == 0)
    		return 0;
    	int i, count = 0, l = 0,r = people.size()-1;
        sort(people.begin(), people.end());
        while( l <= r){
        	if(people[l] + people[r] <= limit){
        		l = l + 1;
        		r = r - 1;
        	}
        	else
        		r = r - 1;
        	count = count + 1;
        }
        return count;
    }
};



// O(n^2)  Time exceed
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    	if(people.size() == 0)
    		return 0;
        int used[people.size()] = {0};
        int i, j, max, sum = 0, count = 0, loc;

        for(i=0;i<people.size();i++){
        	if(used[i] == 0){
        		sum = people[i];
        		max = sum;
        		loc = -1;
	        	for(j=i+1;j<people.size();j++){
	        		if(max == limit)
	        			break;
	        		if(used[j] == 0 && sum + people[j] <= limit && sum + people[j] >= max){
	        			loc = j;
	        			max = sum + people[j];
	        		}
	        	}
	        	if(loc != -1)
	        		used[loc] = 1;
	        	count = count + 1;
	        }
        }
        return count;
    }
};
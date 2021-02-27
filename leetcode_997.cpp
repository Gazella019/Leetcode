


// Runtime: 148 ms, faster than 97.93% of C++
// Memory Usage: 42 MB, less than 100.00% of C++
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int trustOther[N+1] = {0};
        int trusted[N+1] = {0};
        int i;

        for(i=0;i<trust.size();i++){
        	trustOther[trust[i][0]] = 1;
        	trusted[trust[i][1]] += 1;
        }
        for(i=1;i<N+1;i++){
        	if(trustOther[i] == 0 && trusted[i] == N-1)
        		return i;
        }
        return -1;
    }
};
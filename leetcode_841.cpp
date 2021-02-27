




class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	if(rooms.size() == 0)
    		return true;
    	vector<int> visited(rooms.size(), 0);
    	int count = 1;
    	visited[0] = 1;
    	traversal(rooms, visited, 0, &count);
    	if(count == rooms.size())
    		return true;
    	return false;
    }

    void traversal(vector<vector<int>>& rooms, vector<int>& visited, int n, int* count){
    	if(*count == rooms.size())
    		return;
    	for(int i=0;i<rooms[n].size();i++){
    		if(visited[rooms[n][i]] == 0){
    			visited[rooms[n][i]] = 1;
    			*count = *count + 1;
    			traversal(rooms, visited, rooms[n][i], count);
    		}
    	}
    }
};
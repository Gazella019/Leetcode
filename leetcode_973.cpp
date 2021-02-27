




class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
  		vector<int> v;
  		vector<vector<int>> res;
  		int i, max;
  		//map<int, int> hash;
  		//priority_queue<int,vector<int>,greater<int>> pq;

  		for(i=0;i<points.size();i++){
  			v.push_back(pow(points[i][0]) + pow(points[i][1]));
  		}      

  		sort(v.begin(), v.end());
  		max = v[K-1];
  		for(i=0;i<points.size();i++){
  			if(pow(points[i][0]) + pow(points[i][1]) <= max)
  				res.push_back(points[i]);
  		}
  		return res;
    }

    int pow(int x){
    	return x*x;
    }
};
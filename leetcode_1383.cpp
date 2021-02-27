

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
  		
  		int i, j;
  		long sum = 0, mx = 0;
  		int mod = 1000000007;      
  		priority_queue <long, vector<long>, greater<long>> pq;
  		vector<vector<int>>  v;

  		for(i=0;i<speed.size();i++){
  			v.push_back({efficiency[i], speed[i]});
  		}
  		
  		sort(v.begin(), v.end());

  		for(i=v.size()-1;i>=0;i--){
  			pq.push(v[i][1]);
  			sum = sum + v[i][1];
  			while(pq.size() > k){
  				sum = sum - pq.top();
  				pq.pop();
  			}
  			mx = max(mx, sum * v[i][0]);
  		}
  		return mx%mod;
    }
};




// DP sol
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
  		
  		int mod = 1000000007;      
  		int i, cnt, res = 0, num, spe, eff;
  		// table {speed, eff};
  		vector<vector<int>> dp(speed.size(), vector<int>(k+1, 0));
  		vector<vector<vector<int>>> table(speed.size(), vector<vector<int>>(k+1));

  		dp[i][1] = speed[0] * efficiency[0];
  		res = dp[i][1];
  		table[0][1] = {speed[0], efficiency[0]};
  		for(i=1;i<speed.size();i++){
  			if(speed[i]*efficiency[i] > dp[i-1][1]){
  				dp[i][1] = speed[i]*efficiency[i];
  				table[i][1] = {speed[i], efficiency[i]};
  				res = max(res, dp[i][1]);
  			}
  			else{
  				dp[i][1] = dp[i-1][1];
  				table[i][1] = table[i-1][1];
  				res = max(res, dp[i][1]);
  			}
  		}

  		for(cnt=2;cnt<=k;cnt++){
  			for(i=0;i<cnt-1;i++){
  				dp[i][cnt] = dp[i][cnt-1];
  			}
  			for(i=cnt-1;i<speed.size();i++){
  				spe = speed[i]+table[i-1][cnt-1][0];
  				eff = min(efficiency[i], table[i-1][cnt-1][1]);
  				num = spe * eff;
  				if(i == cnt-1){
  					dp[i][cnt] = num;
  					table[i][cnt] = {spe, eff};
  					res = max(res, dp[i][cnt]);
  				}
  				else{
  					if(num > dp[i-1][cnt]){
  						dp[i][cnt] = num;
  						table[i][cnt] = {spe, eff};
  						res = max(res, dp[i][cnt]);
  					}
  					else{
  						dp[i][cnt] = dp[i-1][cnt];
  						table[i][cnt] = table[i-1][cnt];
  						res = max(res, dp[i][cnt]);
  					}
  				}
  			}
  		}

  		return res%mod;
    }
};
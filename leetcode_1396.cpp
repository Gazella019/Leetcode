





class UndergroundSystem {
public:

	map<pair<string, string>, pair<int, int>> res;
	map<int, pair<string, int>> mp;

    UndergroundSystem() {
        
        mp = map<int, pair<string, int>>();
       	res = map<pair<string, string> , pair<int, int>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
     	
     	pair<string, string> p;
     	pair<int, int> pi;
     	int total, cnt;
     	p = make_pair(mp[id].first, stationName);
     	total = res[p].first;
     	cnt = res[p].second;
     	pi = make_pair(total + t-mp[id].second, cnt+1);
     	mp.erase(id);
     	res[p] = pi;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double ans;
        pair<string, string> p;
        p = make_pair(startStation, endStation);

        return (double)res[p].first / res[p].second;
    }
};

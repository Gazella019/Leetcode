


class TweetCounts {
public: 

	unordered_map<string, vector<int>> hash;

    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
    	hash[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        
        int i, start, end, count ,interval, l;
        if(freq == "minute")
        	interval = 60;
        else if(freq == "hour")
        	interval = 3600;
        else if(freq == "day")
        	interval = 86400;

       	l = (endTime - startTime) / interval;

        vector<int> res(l+1, 0);

        for(i=0;i<hash[tweetName].size();i++){
        	if(hash[tweetName][i] >= startTime && hash[tweetName][i] <= endTime)
        		res[(hash[tweetName][i]-startTime)/interval] += 1;
        }
        
        return res;
    }
};

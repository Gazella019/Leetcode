

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        string res;
        int cnt = 0;
        priority_queue<pair<int, char>> pq;
        if(a != 0)
            pq.push({a, 'a'});
        if(b != 0)
            pq.push({b, 'b'});
        if(c != 0)
            pq.push({c, 'c'});

        while(pq.size() > 1){
            pair<int, char> x;
            pair<int, char> y;
            x = pq.top(), pq.pop();
            y = pq.top(), pq.pop();
            if(cnt < 2){
                if(x.first >= 2){
                    res += x.second;
                    res += x.second;
                    cnt += 2;
                    x.first -= 2;
                }
                else{
                    res += x.second;
                    cnt ++;
                    x.first --;
                }
            }
            else{
                if(res[cnt-1] == x.second && res[cnt-2] == x.second){
                    res += y.second;
                    cnt ++;
                    y.first -= 1;
                }
                else{
                    if(x.first >= 2){
                        res += x.second;
                        res += x.second;
                        cnt += 2;
                        x.first -= 2;
                    }
                    else{
                        res += x.second;
                        cnt ++;
                        x.first --;
                    }
                }
            }
            if(x.first > 0)
                pq.push(x);
            if(y.first > 0)
                pq.push(y);
        }
        if(pq.size() == 0 || (res[cnt-1] == pq.top().second) && (res[cnt-2] == pq.top().second))
            return res;
        if(pq.top().first >= 2 && res[cnt-1] != pq.top().second){
            res += pq.top().second;
            res += pq.top().second;
        }
        else
            res += pq.top().second;
        return res;
    }
};




class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        int n1, n2;
    	string res;
    	priority_queue<pair<int, char>> pq;
        if(a != 0)
            pq.push({a, 'a'});
        if(b != 0)
            pq.push({b, 'b'});
        if(c != 0)
            pq.push({c, 'c'});

        while(pq.size() > 1){
        	pair<int, char> n1;
            pair<int, char> n2;
            n1 = pq.top(), pq.pop();
            n2 = pq.top(), pq.pop();
            if(n1.first >= 2){
                res += n1.second;
                res += n1.second;
                n1.first -= 2;
            }
            else{
                res += n1.second;
                n1.first --;
            }
            if(n2.first >= 2 && n2.first >= n1.first){
                res += n2.second;
                res += n2.second;
                n2.first -= 2;
            }
            else{
                res += n2.second;
                n2.first --;
            }
            if(n1.first > 0){
                pq.push(n1);
            }
            if(n2.first > 0){
                pq.push(n2);
            }
        }
        if(pq.size() == 0)
            return res;
      	if(pq.top().first>=2){
            res += pq.top().second;
            res += pq.top().second;
        }
        else{
            res += pq.top().second;
        }
      	return res;
    }

};




class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        int i, j, res = 0;
        int mod = 1000000000 + 7;
        stack<int> s;
        stack<int> s2;
        vector<int> left(A.size(), -1);
        vector<int> right(A.size(), -1);

        for(i=0;i<A.size();i++){
            while(s.size() != 0 && A[s.top()] >= A[i]){
                s.pop();
            }
            if(s.size() == 0)
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
            while(s2.size() != 0 && A[i] <= A[s2.top()]){
                right[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }

        for(i=0;i<A.size();i++){
            if(left[i] == -1)
                left[i] = i+1;
            else
                left[i] = i-left[i];
            if(right[i] == -1)
                right[i] = A.size()-i;
            else
                right[i] = right[i]-i;
            res = res + A[i]*(left[i]*right[i]);
            res = res % mod;
        }

        for(i=0;i<left.size();i++){
            cout << left[i] << "　";
        }
        cout << endl;
        for(i=0;i<right.size();i++){
            cout << right[i] << "　";
        }
        cout << endl;

        return res;
    }
};


class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        int i, j, mn = INT_MAX, res = 0;
        int mod = 1000000000 + 7;

        for(i=0;i<A.size();i++){
            mn = INT_MAX;
            for(j=i;j<A.size();j++){
                mn = min(mn, A[j]);
                res = res + mn;
                res = res % mod;
            }
        }

        return res;
    }
};
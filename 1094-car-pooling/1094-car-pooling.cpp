typedef pair<int, int> pi;

class Solution {
public:
    
    static bool comp( vector<int>& a, vector<int>& b ){
        if( a[1] == b[1] ){
            return a[2] < b[2];
        }
        
        return a[1] < b[1] ;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        long long n = trips.size(), fr = capacity;
        
        sort( trips.begin(), trips.end(), comp );
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        for( int i = 0 ; i < n ; i++ ){
            int s = trips[i][1], e = trips[i][2], p = trips[i][0];
            
            while( !pq.empty() ){
                int drop = pq.top().first, vac = pq.top().second;
                if( drop <= s ){
                    fr += vac;
                    pq.pop();
                }
                else{
                    break;
                }
            }
            
            if( fr - p >= 0 ){
                fr -= p;
                pq.push({ e,p });
            }
            else{
                return false;
            }
        }
        return true;
    }
};
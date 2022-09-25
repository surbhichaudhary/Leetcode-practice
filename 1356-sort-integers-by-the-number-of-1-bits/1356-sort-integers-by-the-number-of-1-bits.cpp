typedef pair<int, int> pi;

class Solution {
public:
    
    static bool comp( pi& a, pi& b ){
        if( a.first == b.first ){
            return a.second < b.second;
        }
        
        return a.first < b.first ;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pi> pq;
        for( int i = 0 ; i < arr.size() ; i++ ){
            int num = arr[i], c=0;
            while( num > 0 ){
                if( num&1 ){
                    c++;
                }
                num >>= 1;
            }
            pq.push_back({ c, arr[i] });
        }
        
        sort( pq.begin(), pq.end(), comp );
        vector<int> ans;
        for( int i = 0 ; i < arr.size() ; i++ ){
            ans.push_back( pq[i].second );
        }
        return ans;
    }
};

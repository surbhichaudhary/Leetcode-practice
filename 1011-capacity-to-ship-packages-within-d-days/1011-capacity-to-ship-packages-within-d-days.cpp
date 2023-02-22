class Solution {
public:
    
    bool Possible( long long m, vector<int>& weights, int days ){
        long long n = weights.size(), w = 0, k = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            w += weights[i];
            
            if( w > m ){
                k++;
                w = weights[i];
            }
            if( k > days )
                return false;
        }
        k++;
        return ( k <= days );
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        long long e = 0, s = weights[0], n = weights.size(), ans = INT_MAX;
        
        for( int i = 0 ; i < n ; i++ ){
            e += weights[i];
            s = ( s >= weights[i] ) ? s : weights[i];
        }
        
        while( s <= e ){
            long long m = s + ((e-s)/2);
            
            if( Possible( m, weights, days ) ){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};
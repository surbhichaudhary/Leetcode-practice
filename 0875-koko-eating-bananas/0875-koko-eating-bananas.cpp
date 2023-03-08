class Solution {
public:
    
    bool isPossible( int m, vector<int>& piles, int h ){
        int t = 0;
        for( int i = 0 ; i < piles.size() ; i++ ){
            t += ( piles[i]/m );
            t += (( ( piles[i]%m ) > 0 ) ? 1 : 0 );
            
            if( t > h ){
                return false;
            }
        }
        
        return ( t <= h );
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1, e = 0, ans;
        for( int i =0 ; i < piles.size() ; i++ ){
            e += piles[i];
            s = min( s, (long long)piles[i] );
        }
        
        while( s <= e ){
            long long m = s + ( e-s )/2;
            if( isPossible( m, piles, h ) ){
                ans  = min( ans, m );
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        
        return ans;
    }
};
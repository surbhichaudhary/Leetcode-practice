typedef long long ll;

class Solution {
public:
    
    bool isPossible( ll t, int cars, vector<int>& ranks ){
        int k=0;
        
        for( int i = 0 ; i < ranks.size() ; i++ ){
            k += sqrt( t/ranks[i] );
            
            if( k >= cars ){
                return true;
            }
        }
        return ( k >= cars );
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        sort( ranks.begin(), ranks.end() );
        ll n = ranks.size(), s = 1, e = ranks[n-1]* cars;
        e *= cars;
        ll ans = e;
        
        while( s <= e ){
            ll m = s + (e-s)/2;
            
            if( isPossible( m, cars, ranks ) ){
                ans = min( ans, m );
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        
        return ans;
        
    }
};
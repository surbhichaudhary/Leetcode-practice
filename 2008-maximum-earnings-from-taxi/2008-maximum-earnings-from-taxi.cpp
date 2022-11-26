typedef long long ll;

class Solution {
public:
    
    int dest, sz;
    
    static bool comp( vector<int>& a, vector<int>& b ){
        return ( a[0] < b[0] );
    }
    
    int pickup( int i, vector<vector<int>>& rides ){
        int s = i+1, e = sz-1, ans = sz;
        
        while( s <= e ){
            int m = s + ( e-s )/2;
            
            if( rides[m][0] >= rides[i][1] ){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
            
        }
        
        return ans;
    }
    
    ll solve( int i, vector<vector<int>>& rides, vector<ll>& dp ){
        if( i >= sz ){
            return 0;
        }
        if( dp[i] != -1 ) {
            return dp[i];
        }
        //not picking current passenger
        ll ans = solve( i+1, rides, dp );
        // if picking up current passenger
        int pos = pickup( i, rides ), money = rides[i][1] - rides[i][0] + rides[i][2];
        ans = max( ans, money + solve( pos, rides, dp ) );
        
        return dp[i] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        dest = n, sz = rides.size();
        sort( rides.begin(), rides.end(), comp );
        vector<ll> dp( sz, -1 );
        
        return solve( 0, rides, dp );
        
    }
};
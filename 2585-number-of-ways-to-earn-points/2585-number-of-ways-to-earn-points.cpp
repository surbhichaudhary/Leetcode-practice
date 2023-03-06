typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<vector<ll>> vvl;

class Solution {
public:
    
    int m = 1e9 + 7;
    
    ll solve( int i, int t, vvi& types, vvl& dp ){
        if( (i >= types.size() ) || (t <= 0) ){
            return ( t == 0 );
        }
        if( dp[i][t] != -1 ){
            return dp[i][t]%m;
        }
        
        ll ans = solve( i+1, t, types, dp );
        for( int j = 1 ; j <= types[i][0] ; j++ ){
            ll curr = types[i][1]*j;
            if( curr <= t ){
                ans += solve( i+1, t-curr, types, dp ) ;
            }
        }
        return ( dp[i][t] = ans%m );
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size(), s = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            s += ( types[i][0] * types[i][1] );
        }
        
        if( s == target ){
            return 1;
        }
        
        vvl dp( n, vector<ll>( target+1, -1 ));
        
        return solve( 0, target, types, dp );
    }
};
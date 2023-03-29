typedef long long ll;

class Solution {
public:
    
    ll solve( int i, int j, vector<int>& satisfaction, vector<vector<ll>>& dp ){
        if( i >= satisfaction.size() ){
            return 0;
        }
        
        if( dp[i][j] != LLONG_MAX ){
            return dp[i][j];
        }
        
        ll exc = solve( i+1, j, satisfaction, dp );
        ll inc = ( j*satisfaction[i] ) + solve( i+1, j+1, satisfaction, dp );
        
        return ( dp[i][j] = max( inc, exc ) );
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort( satisfaction.begin(), satisfaction.end() );
        int n = satisfaction.size();
        vector<vector<ll>> dp( n+1, vector<ll>( n+1, LLONG_MAX ) );
        
        ll ans = max( ll(0), solve( 0, 1, satisfaction, dp ) );
        
        return ans;
    }
};
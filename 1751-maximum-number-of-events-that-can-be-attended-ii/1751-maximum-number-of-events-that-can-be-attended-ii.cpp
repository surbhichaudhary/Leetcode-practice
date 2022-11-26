typedef long long ll;

class Solution {
public:
    
    int n;
    
    static bool comp( vector<int>& a, vector<int>& b ){
        if( a[0] == b[0] ){
            return a[1] < b[1];
        }
        return ( a[0] < b[0] );
    }
    
    static bool value( vector<int>& a, vector<int>& b ){
        return a[2] > b[2];
    }
    
    int next( int i, vector<vector<int>>& events ){
        int s = i+1, e = n-1, ans = n;
        
        while( s <= e ){
            int m = s + ( e-s )/2;
            
            if( events[m][0] > events[i][1] ){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        
        return ans;
    }
    
    ll solve( int i, int k, vector<vector<int>>& events, vector<vector<ll>>& dp ){
        if( (i >= n) || (k <= 0) ){
            return 0;
        }
        if( dp[i][k] != -1 ){
            return dp[i][k];
        }
        //not attending current event
        ll ans = solve( i+1, k, events, dp );
        //when attending current event;
        int pos = next( i, events );
        ans = max( ans, events[i][2] + solve( pos, k-1, events, dp ) );
        
        return dp[i][k] = ans;
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        
        if( k == 1 ){
            sort( events.begin(), events.end(), value );
            return events[0][2];
        }
        
        sort( events.begin(), events.end(), comp );
        vector<vector<ll>> dp( n, vector<ll>( k+1, -1 ) );
        
        return solve( 0, k, events, dp );
    }
};
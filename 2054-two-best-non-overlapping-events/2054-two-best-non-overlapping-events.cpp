class Solution {
public:
    
    static bool comp( vector<int>& a, vector<int>& b ){
        if( a[0] == b[0] ){
            return ( a[1] < b[1] );
        }
        return ( a[0] < b[0] );
    }
    
    int next( int i, vector<vector<int>>& events ){
        int s = i+1, e = events.size()-1, ans = events.size();
        
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
    
    int solve( int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp ){
        if( (i >= events.size()) || (k <= 0) ){
            return 0;
        }
        if( dp[i][k] != -1 ){
            return dp[i][k];
        }
        int ans = solve( i+1, k, events, dp );
        
        int pos = next( i, events );
        ans = max( ans, events[i][2] + solve( pos, k-1, events, dp ) );
        
        return dp[i][k] = ans;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort( events.begin(), events.end(), comp );
        int n = events.size();
        
        vector<vector<int>> dp( n+1, vector<int>( 3, -1 ) );
        
        return solve( 0, 2, events, dp );
        
    }
};
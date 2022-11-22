class Solution {
public:
    
    int n;
    
    int solve( int i, int lp, vector<int>& prices, vector<vector<int>>& dp ){
        if( i >= prices.size() ){
            return 0;
        }
        if( i == n - 1 ){
            if( lp < n ){
                return ( max( 0, prices[i] - prices[lp] ) );
            }
            return 0;
        }
        if( dp[i][lp] != -1 ){
            return dp[i][lp];
        }
        
        int ans = 0;
        if( lp >= n ){
            //buying today
            ans = solve( i+1, i, prices, dp );
        }
        else{
            //selling today
            ans = (prices[i] - prices[lp]) + solve( i+2, n+1, prices, dp );
        }
        //neither buying nor selling today
        ans = max( ans, solve( i+1, lp, prices, dp ) );
        
        return (dp[i][lp] = ans);
    }
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp( n+1, vector<int>( n+5, -1 ));
        
        return solve( 0, n+1, prices, dp );
    }
};
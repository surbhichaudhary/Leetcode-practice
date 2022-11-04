class Solution {
public:
    
    unordered_map<int, int> dp;
    
    int solve( int n ){
        if( n <= 0 ){
            return 0;
        }

        if( dp.find(n) != dp.end() ){
            return dp[n];
        }
        
        int ans = INT_MAX, h = n/2, t = n/3;
        
        if( n%3 == 0 ){
            ans = min( ans, solve( t) );
        }
        if( n%2 == 0 ){
            ans = min ( ans , solve( h) );
        }
        if( (n%3 != 0) || (n%2 != 0) ){
            ans = min( ans , solve( n-1 ) );
        }
        
        return (dp[n] = (1 + ans));
    }
    
    int minDays(int n) {
        if( n < 3 ){ 
            return n;
        }
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        return solve( n );
        
    }
};


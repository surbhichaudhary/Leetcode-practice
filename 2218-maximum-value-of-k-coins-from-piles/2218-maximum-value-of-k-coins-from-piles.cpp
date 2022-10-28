typedef long long ll;
#include<algorithm>

class Solution {
public:
    
    ll solve( int i, int k, vector<vector<int>>& piles, vector<vector<ll>>& t ){
        if( k <= 0 || i < 0 ){
            return 0;
        }
        if( t[i][k] != -1 ){
            return t[i][k];
        }
        
        ll exc = solve( i-1, k, piles, t );
        ll inc = 0, sum = 0, n = piles[i].size() < k ? piles[i].size() : k ;
        
        for( ll j = 0 ; j < n ; j++ ){
            sum += piles[i][j];
            inc = max( inc, sum+solve( i-1, k-j-1, piles, t) );
        }
        
        t[i][k] = max( exc, inc );
        return t[i][k];
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<ll>> t( n+1, vector<ll>(k+1, -1) );
        return solve( n-1, k, piles, t );
    }
};
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if( n<1 ){
            return 0;
        }
        
        vector<vector<int>> t( k+1, vector<int>( n, 0 ));
        
        for( int i = 1 ; i <= k ; i++ ){
            int val = INT_MIN;
            for( int j = 1 ; j < n ; j++ ){
                if( t[i-1][j-1] - prices[j-1] > val ){
                    val = t[i-1][j-1] - prices[j-1];
                }
                if( val + prices[j] > t[i][j-1] ){
                    t[i][j] = val + prices[j];
                }
                else{
                    t[i][j] = t[i][j-1];
                }
            }
        }
        return t[k][n-1];
    }
};
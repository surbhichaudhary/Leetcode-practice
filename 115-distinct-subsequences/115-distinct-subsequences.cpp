#define m 1000000007

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<vector<long long>> dp( n1+1, vector<long long>(n2+1, 0) );
        
        for( int i=0; i<= n1; i++ ){
            for( int j = 0 ; j<=n2 ;j++ ){
                if( j == 0 ){
                    dp[i][j] = 1;
                }
                else if( i == 0 ){
                    dp[i][j] = 0;
                }
                else if ( s[i-1] == t[j-1] ){
                    dp[i][j] = (dp[i-1][j-1]%m + dp[i-1][j]%m)%m;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n1][n2];
    }
};
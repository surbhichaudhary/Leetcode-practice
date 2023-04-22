class Solution {
public:
    int minInsertions(string s) {
        string p = s;
        reverse( p.begin(), p.end() );
        int n = s.length();
        
        vector<vector<int>> t( n+1, vector<int> ( n+1, 0 ) );
        
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( s[i-1] == p[j-1] ){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max( t[i-1][j], t[i][j-1] );
                }
            }
        }
        
        return ( n - t[n][n] );
    }
};
class Solution {
public:
  
    bool solve( int i, int j, string& s, string& p, vector<vector<int>>& t ){
        if( i < 0 && j < 0 ) return true;
        
        if( i >= 0 && j < 0 ) return false;
        
        if( i < 0 && j >= 0 ) {
            for( int k = 0 ; k <= j ; k++ ){
                if( p[k] != '*' ){
                    return false;
                }
            }
            return true;
        }
        
        if( t[i][j] != -1 )
            return t[i][j];
        
        else if( p[j] == '*' ){
            return t[i][j] = (solve( i-1, j, s, p, t ) || solve( i, j-1, s, p, t ));
        }
        else if( p[j] == '?' || p[j] == s[i] ){
            return t[i][j] = solve( i-1, j-1, s, p, t );
        }
        return t[i][j] = false;
    }
    
    bool isMatch(string& s, string& p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> t( n, vector<int>(m, -1 ) );
        return solve( n-1, m-1, s, p, t );
    }
};
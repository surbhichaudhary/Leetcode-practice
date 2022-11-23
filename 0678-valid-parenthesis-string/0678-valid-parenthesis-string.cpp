class Solution {
public:
    
    int solve( int i, int op, string& s, vector<vector<int>>& t ){
        if( i >= s.length() ){
            return ( op == 0 );
        }
        if( op < 0 ){
            return false;
        }
        if( t[i][op] != -1 ){
            return t[i][op];
        }
        
        
        if( s[i] == '(' ){
            return t[i][op] = solve( i+1, op+1, s, t );
        }
        else if( s[i] == ')' ){
            return t[i][op] = solve( i+1, op-1, s, t );
        }
        
        return t[i][op] = ( solve( i+1, op+1, s, t ) || 
                 solve( i+1, op-1, s, t ) || solve( i+1, op, s, t ) );
    }
    
    bool checkValidString(string& s) {
        int n = s.length();
        vector<vector<int>> t( n+1, vector<int>( n+1, -1 ));
        
        return solve( 0, 0, s, t );
    }
};
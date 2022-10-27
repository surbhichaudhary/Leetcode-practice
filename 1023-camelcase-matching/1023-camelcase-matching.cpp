class Solution {
public:
    
    bool solve( int i, int j, string& a, string& b, vector<vector<int>>& t ){
        if( i >= a.length() && j >= b.length() ){
            return true;
        }
        if( t[i][j] != -1 ){
            return t[i][j];
        }
        
        if( a[i] == b[j] ){
            return t[i][j] = solve( i+1, j+1, a, b, t );
        }
        if( islower(a[i]) ){
            return t[i][j] = solve( i+1, j, a, b, t );
        }
        return t[i][j] = false;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n);
        
        for( int i = 0 ; i < n ; i++ ){
            vector<vector<int>> t( 101, vector<int>(101, -1)) ;
            ans[i] = solve( 0, 0, queries[i], pattern, t );
        }
        
        return ans;
    }
};
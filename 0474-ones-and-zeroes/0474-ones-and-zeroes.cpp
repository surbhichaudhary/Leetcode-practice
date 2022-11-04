class Solution {
public:
    
    int solve( int i, int z, int o, vector<string>& strs, int m, int n, 
              vector<vector<vector<int>>>& t ){
        if( i >= strs.size() || ( ( z == m ) && ( o == n ) ) ){
            return 0;
        }
        if( t[i][z][o] != -1 ){
            return t[i][z][o];
        }
        //not included current
        int ans = solve( i+1, z, o, strs, m ,n, t );
        
        int cz =0, co =0;
        for( int j =0 ; j < strs[i].size() ; j++ ){
            if( strs[i][j] == '0' ){
                cz++;
            }
            else{
                co++;
            }
        }
        //included current
        if(( z + cz <= m ) && ( o + co <= n )){
            ans = max( ans, 1 + solve( i+1, z+cz, o+co, strs, m, n, t ) );
        }
        return t[i][z][o] = ans;
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> t(l+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        return solve( 0, 0, 0, strs, m, n, t );
    }
};
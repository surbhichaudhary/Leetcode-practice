typedef long long ll;

class Solution {
public:
    
    ll solve( int i, ll curr, vector<vector<int>>& mat, int& target, vector<vector<ll>>& mp){
        if( i >= mat.size() ){
            return abs( curr - target );
        }
        if( mp[i][curr] != -1 ){
            return mp[i][curr];
        }
        
        ll ans = INT_MAX;
        for( int j = 0 ; j < mat[i].size() ; j++ ){
            ans  = min( ans, solve( i+1, curr+ mat[i][j], mat, target, mp ) );
            if( ans == 0 ){
                return 0;
            }
        }
        return mp[i][curr] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        ll s = 0 , n = mat.size();
        for( int i = 0 ;  i < n ; i++ ){
            int c = mat[i][0];
            for( int j = 1; j < mat[i].size() ;j++ ){
                c = max( c, mat[i][j]);
            }
            s += c;
        }
        
        vector<vector<ll>> mp( n+1, vector<ll>(s+1, -1));
        return solve( 0, 0, mat, target, mp );
    }
};
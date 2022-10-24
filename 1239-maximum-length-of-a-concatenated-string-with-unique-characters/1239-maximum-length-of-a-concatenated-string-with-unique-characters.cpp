class Solution {
public:
    
    int solve( int i, int l, vector<string>& arr, vector<int> t ){
        if( i >= arr.size() ){
            return l;
        }
        
        int ans = solve( i+1, l, arr, t ) ;
        bool flag = true;
        
        for( int j = 0 ; j < arr[i].length() ; j++ ){
            if( t[arr[i][j]-'a'] > 0 ){
                flag = false;
                break;
            }
        }
        
        if( flag ){
            for( int j = 0 ; j < arr[i].length() ; j++ ){
                t[arr[i][j]-'a'] += 1;
                if( t[arr[i][j]-'a'] > 1 ){
                    flag = false;
                }
            }
            if( flag ){
                l += arr[i].length();
                ans = max( ans, solve( i+1, l, arr, t) );
            }
            
        }
        
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> t(26, 0);
        return solve( 0, 0, arr, t );
    }
};
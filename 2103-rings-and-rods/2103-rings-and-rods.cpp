class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> t( 10, vector<int>( 3, 0) );
        for( int i = 0 ; i < rings.size() ; i += 2 ){
            char c = rings[i];
            int r = rings[i+1] - '0', col ;
            
            if( c == 'B' ){
                col = 0;
            }
            else if( c == 'R' ){
                col = 1;
            }
            else if( c == 'G' ){
                col = 2;
            }
            t[r][col]++;
        }
        
        int ans = 0 ;
        for( int i = 0 ; i< 10 ; i++ ){
            if( t[i][0] > 0 && t[i][1] > 0 && t[i][2] > 0 ){
                ans++;
            }
        }
        
        return ans;
    }
};
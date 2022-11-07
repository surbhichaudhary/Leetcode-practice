class Solution {
public:
    bool isThree(int n) {
        vector<int> f( n+1, 1 );
      
        for( int i = 2 ; i <= n ;i++ ){
            int h = i/2;
            for( int j = 1; j<= h; j++ ){
                if( i% j == 0 ){
                    f[i]++;
                }
            }
        }
        
        return (f[n] == 3);
    }
};
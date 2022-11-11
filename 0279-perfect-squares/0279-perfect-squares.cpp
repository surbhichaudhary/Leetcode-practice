class Solution {
public:
    unordered_map< int, int> mp;
   
    int numSquares(int n) {
        
        if( n<4 ){
            return n;
        }
        
        vector<int> sq( n+1, INT_MAX );
        int r = sqrt(n);
        
        mp[1] = 1;
        
        for( int i = 2 ; i <= r ; i++ ){// at max 100 times
            int s = i*i;
            sq[s] = 1;
            mp[i] = s;
        }
        
        sq[0] = 0 ; sq[1] = 1;
        sq[2] = 2 ; sq[3] = 3;
        
        for( int i = 5 ; i <= n ; i++ ){
            for( int j = 1 ; mp.count(j) && (mp[j] <= i ) ; j++ ){
                sq[i] = min( sq[i], 1 + sq[ i-mp[j] ] );
            }
        }
        
        return sq[n];
    }
};
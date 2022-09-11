class Solution {
public:
    int arrangeCoins(int n) {
        if( n < 3 ){
            return 1;
        }
        
        long long c = 1, r = 0;
        
        while( n > 0 ){
            if( n >= c ){
                n -= c;
                r++;
            }
            else{
                break;
            }
            c++;
        }
        
        return r;
    }
};
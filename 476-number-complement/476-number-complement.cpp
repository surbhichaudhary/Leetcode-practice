class Solution {
public:
    int findComplement(int num) {
        int ans = 0, p=0;
        
        while( num > 0 ){
            int r = num&1;
            num = num>>1;
            if( r == 0 ){
                ans += ((int)(pow(2,p)) );
            }
            p++;
        }
        
        return ans;
    }
};
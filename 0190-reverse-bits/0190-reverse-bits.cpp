class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> tmp;
    
        while( n ){
            int curr = n&1;
            tmp.push_back(curr);
            n = n>>1;
        }
        
        while( tmp.size() < 32 ){
            tmp.push_back(0);
        }
        
        uint32_t ans = 0;
        long long p = 1;
        for( int i = 31; i >=0 ; i-- ){
            ans += ( tmp[i] * p );
            p *= 2;
        }
        return ans;
    }
};
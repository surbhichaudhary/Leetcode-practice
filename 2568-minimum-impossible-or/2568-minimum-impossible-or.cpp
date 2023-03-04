class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map< int, int >mp;
        for( auto i : nums ){
            mp[i]++;
        }
        
        long long p = 1;
        while( p <= INT_MAX ){
            if( !mp.count(p) ){
                return p;
            }
            p+= p;
        }
        
        return (0);
    }
};
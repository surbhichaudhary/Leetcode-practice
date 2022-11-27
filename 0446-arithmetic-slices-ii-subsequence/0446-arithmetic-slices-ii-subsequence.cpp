typedef long long ll;

class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        if( n < 3 ){
            return 0;
        }
        // starting at each index - diff - freq
        vector<unordered_map<ll, ll> > mp(n);
        
        for( int i = 1 ; i < n ; i++ ){
            for( int j = 0 ; j < i ; j++ )
            {
                ll d = ll(nums[i]) - ll(nums[j]), s =0;
         
                if( mp[j].count(d) ){
                    s = mp[j][d];
                }
                
                ans += s;
                mp[i][d] += (s+1);
            }
        }
        
        return (int)ans;
    }
};
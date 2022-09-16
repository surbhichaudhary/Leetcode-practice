typedef long long ll;
typedef pair<int, int> pi;

class Solution {
public:
   
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector< vector< ll> > mp( m+1, vector<ll> ( m+1, 0) );
        
        for( int i = m-1 ; i >= 0 ; i-- ){
            for( int j = i ; j >= 0 ; j--){
                mp[i][j] = multipliers[i] * nums[j] + mp[i+1][j+1];
                int k = n - 1 - (i - j);
                
                mp[i][j] = max( mp[i][j], ((multipliers[i] * nums[k]) + mp[i+1][j] ) );
            }
        }
        
        return mp[0][0];
    }
};
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans( n, false );
        
        for( int i =0 ; i < n ;i++ ){
            int curr = candies[i] + extraCandies, mx = curr;
            
            for( int j = 0 ; j < n ; j++ ){
                mx = max( mx, candies[j] );
            }
            
            if( mx == curr ){
                ans[i] = true;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size(), l = n-k, s =0, w = 2*k +1, f = 0, e = w;
        vector<int> ans( n, -1 );
        
        //cout<<n<<endl;
        if( k >= n ) {
            return ans;
        }
        
        for( int i = 0 ; (i < n) && (i < w) ; i++ ){
            s += nums[i];
        }
        
        for( int  i = k ; i < l ; i++ ){
            long long curr = s/w;
            ans[i] = curr;
            s -= nums[f];
            f++;
            if( e < n ){
                s += nums[e];
            }
            e++;
        }
        
         return ans;
        
    }
};
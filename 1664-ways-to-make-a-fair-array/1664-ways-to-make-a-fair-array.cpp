class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), ans =0;
        
        if( n == 1 ){
            return 1;
        }
        
        vector<int> le(n, 0);
        vector<int> lo(n, 0);
        vector<int> re(n, 0);
        vector<int> ro(n, 0);
        
        le[0] = nums[0];
        for( int i = 1 ; i< n ;i++ ){
            if( i%2 == 0 ){
                le[i] = le[i-1] + nums[i];
                lo[i] = lo[i-1];
            }
            else{
                lo[i] = lo[i-1] + nums[i];
                le[i] = le[i-1];
            }
        }
        
        if( n%2 == 0 ){
            ro[n-1] = nums[n-1];
        }
        else{
            re[n-1] = nums[n-1];
        }
        
        for( int i = n-2 ; i >=0 ; i-- ){
            if( i%2 == 0 ){
                re[i] = re[i+1] + nums[i];
                ro[i] = ro[i+1];
            }
            else{
                ro[i] = ro[i+1] + nums[i];
                re[i] = re[i+1];
            }
        }
        
        if( re[1] == ro[1] ){
            ans++;
        }
        if( lo[n-2] == le[n-2] ){
            ans++;
        }
        
        for( int i = 1 ; i < n-1 ; i++ ){
            if( (le[i-1] + ro[i+1]) == (lo[i-1] + re[i+1]) ){
                ans++;
            }
        }
        
        return ans;
    }
};

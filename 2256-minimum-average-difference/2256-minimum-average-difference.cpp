class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), ans= -1, mn= INT_MAX;
        
        vector<long long> lft( n, 0 );
        vector<long long> rgt( n, 0 );
        
        lft[0] = nums[0];
        for( int i = 1 ; i < n ; i++ ){
            lft[i] = lft[i-1] + nums[i];
        }
        
        rgt[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i-- ){
            rgt[i] = rgt[i+1] + nums[i];
        }
        
        mn = lft[n-1] / n, ans = n-1;
        
        for( int i = 0 ; i < n-1 ; i++ ){
            double d1 = lft[i] / (i+1.0) ;
            double d2 = rgt[i+1] / (n-i-1.0) ;
            
            int d = abs( (int)(d1)-(int)(d2) );
            if( (d < mn) || (( d == mn) && (i < ans) ) ){
                mn = d;
                ans= i;
            }
        }
        
        return ans;
        
        
    }
};
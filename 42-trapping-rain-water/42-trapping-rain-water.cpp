class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water =0;
        
        int max_l[n];
        int max_r[n];
        
        max_l[0] = height[0];
        for( int i=1; i<n ; i++ ){
            max_l[i] = max( height[i], max_l[i-1] );
        }
        
        max_r[n-1] = height[n-1];
        for( int  i =n-2; i>=0 ; i-- ){
            max_r[i] = max( max_r[i+1], height[i] );
        }
        
        for( int i=0; i<n ;i++ ){
            water+= min(max_l[i], max_r[i] )- height[i];
        }
        return water;
    }
};
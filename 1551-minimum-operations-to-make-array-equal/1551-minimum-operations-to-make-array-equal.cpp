class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n,0);
        int s =0, ans =0, h = n/2 ;
        
        for( int i =0 ; i< n ;i++ ){
            arr[i] = ( i + i + 1 );
            s += arr[i];
        }
        
        int req = s/n;
        for( int i =0 ; i < h ; i++ ){
            ans += ( req - arr[i] );
        }
        
        return ans;
    }
};
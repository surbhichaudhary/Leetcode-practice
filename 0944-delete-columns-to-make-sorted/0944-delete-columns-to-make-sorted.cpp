class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans =0;
        
        for( int i =0 ; i< m ;i++ ){
            char curr = strs[0][i], mx = strs[0][i];
            for( int j =1 ;j < n ; j++ ){
                if( (strs[j][i] < curr) || (strs[j][i] < mx) ){
                    ans++;
                    break;
                }
                curr = strs[j][i];
                mx = max( mx, curr );
            }
        }
        
        return ans;
    }
};
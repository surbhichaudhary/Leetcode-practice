class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0, l = left.size(), r = right.size() ;
        
        for( int i = 0 ; i < l ; i++ ){
            ans = max( ans, left[i] );
        }
        for( int i = 0 ; i < r ; i++ ){
            ans = max( ans, n-right[i] );
        }
        
        return ans;
    }
};
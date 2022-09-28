class Solution {
public:
    int numSub(string s) {
        long long i=0, j=0, ans = 0, n = s.length(), m = 1000000007;
        while( j<n ){
            if( s[j] == '0' ){
                i = j+1;
            }
            else{
                ans = ( ans%m + (j-i+1)%m )%m;
            }
            j++;
        }
        
        return ans;
    }
};
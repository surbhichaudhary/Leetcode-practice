class Solution {
public:
    int countHomogenous(string& s) {
        long long i=0, j=0, ans = 0, n = s.length(), m = 1000000007;
        char c = s[0];
        
        while( j < n ){
            if( s[j] != c ){
                c = s[j];
                i = j;
            }
            ans = ( ans%m + (j-i+1)%m )%m;
            j++;
        }
        return ans;
    }
};

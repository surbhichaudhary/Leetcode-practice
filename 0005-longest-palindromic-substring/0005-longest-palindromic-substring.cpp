class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length(), ans = 1, st = 0;
        string res="";
        
        for( int i = 1 ; i < n ; i++ ){
            int j = 1;
            //odd length
            while( (i >= j) && (j+i < n ) && (s[i-j] == s[i+j]) ){
                int curr = j+j+1;
                if( curr > ans ){
                    ans = curr;
                    st = i-j;
                }
                j++;
            }
            j=0;
            //even length
            while( (i >= (j+1)) && (i+j <= n) && ( s[i-j-1] == s[i+j] ) ){
                int curr = j+j+2;
                if( curr > ans ){
                    ans = curr;
                    st = i-j-1;
                }
                j++;
            }
        }
        return s.substr(st, ans);
    }
};
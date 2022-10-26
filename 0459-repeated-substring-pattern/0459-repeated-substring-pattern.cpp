class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
       
        for( int i = 0 ; i < n ; i++ ){
            
            string sb = s.substr( 0, i+1 );
            string ans = "";
            if( n % sb.length() == 0 && sb.length() != n ){
                
                int q = n/sb.length();
                for( int j = 1 ; j <= q ; j++ ){
                    ans += sb;
                }
            
                if( ans == s ){
                    return true;
                }
            }
        }
        
        return false;
    }
};
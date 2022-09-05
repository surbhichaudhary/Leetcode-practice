class Solution {
public:
  
    int countSubstrings(string s) {
        int ans = 0;
        //odd length
        for( int i = 0 ; i < s.length() ; i++ ){
            int x = 0;
            while( i-x >= 0 && i+x < s.length()  && s[i-x] == s[i+x] ){
                ans++;
                x++;
            }
        }
        //even length
        for( int i = 0; i < s.length()-1 ; i++ ){
            if( s[i] == s[i+1] ){
                int x = 0;
                while( i-x >= 0 && i+1+x < s.length()  && s[i-x] == s[i+1+x] ){
                    ans++;
                    x++;
                }
            }
        }
        return ans;
    }
};
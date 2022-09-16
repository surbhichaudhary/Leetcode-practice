class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0, st=-1;
        //odd length
        for( int i = 0 ; i < s.length() ; i++ ){
            int x = 0;
            while( i-x >= 0 && i+x < s.length()  && s[i-x] == s[i+x] ){
                int l = 2*x+1;
                if( l > ans ){
                    ans = l;
                    st = i-x;
                }
                x++;
            }
        }
        //even length
        for( int i = 0; i < s.length()-1 ; i++ ){
            if( s[i] == s[i+1] ){
                int x = 0;
                while( i-x >= 0 && i+1+x < s.length()  && s[i-x] == s[i+1+x] ){
                    int l = 2*x+2;
                    if( l > ans ){
                        ans = l;
                        st = i-x;
                    }
                    x++;
                }
            }
        }
        
        string pal = s.substr(st, ans);
        return pal;
    }
};

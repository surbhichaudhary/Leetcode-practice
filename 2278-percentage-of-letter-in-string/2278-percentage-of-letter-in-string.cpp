class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length(), p =0;
        for( int i =0; i< n ;i++ ){
            if( s[i] == letter ){
                p++;
            }
        }
        
        int ans = (p*100)/n;
        return ans;
    }
};
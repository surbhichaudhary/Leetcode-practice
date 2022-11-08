class Solution {
public:
    bool areNumbersAscending(string s) {
        int lp = -1, n = s.length(), i=0;
        
        while( i < n ){
            if( isdigit(s[i]) ){
                int j = i, val = 0;
                
                while( j < n && isdigit(s[j]) ){
                    val *= 10;
                    val += ( s[j] - '0' );
                    j++;
                }
                
                if( val <= lp ){
                    return false;
                }
                
                lp = val;
                i = j;
            }
            else{
                i++;
            }
        }
        
        return true;
    }
};
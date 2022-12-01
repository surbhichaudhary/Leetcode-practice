class Solution {
public:
    
    bool isVowel( char c ){
        if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
            (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')  ){
            return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.length(), h = n/2;;
        int c1= 0 , c2 =0 ;
        
        for( int i = 0 , j = h ; (i < h) && (j < n) ; i++, j++ ){
            if( isVowel( s[i] ) ){
                c1++;
            }
            if( isVowel( s[j] ) ){
                c2++;
            }
        }
        
        return ( c1 == c2 );
    }
};
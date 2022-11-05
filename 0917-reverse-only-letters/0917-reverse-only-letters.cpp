class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i =0, j = s.length()-1;
        
        while( i < j ){
            if( isalpha(s[i]) && isalpha(s[j]) ){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if( isalpha(s[i]) && !isalpha(s[j]) ){
                j--;
            }
            else if( !isalpha(s[i]) && isalpha(s[j]) ){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        
        return s;
        
    }
};
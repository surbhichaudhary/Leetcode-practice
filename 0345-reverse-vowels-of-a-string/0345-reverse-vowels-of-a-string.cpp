class Solution {
public:
    
    bool isVowel( char c ){
        if( (c =='a') || (c =='e') || (c == 'i') || (c == 'o') || (c =='u') ||
          (c =='A') || (c =='E') || (c == 'I') || (c == 'O') || (c =='U') ){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int i=0, j = s.length()-1;
        while( i < j ){
            bool  vi = isVowel(s[i]), vj = isVowel(s[j]);
            if( vi && vj ){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if( vi && (!vj) ){
                j--;
            }
            else if( (!vi) && vj ){
                i++;
            }
            else if( (!vi) && (!vj) ){
                i++;
                j--;
            }
        }
        
        return s;
    }
};
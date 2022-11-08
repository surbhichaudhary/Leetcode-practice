class Solution {
public:
    bool checkString(string s) {
        int n = s.length(), i =0 , la= -1, fb = n;
        
        for( ; i <n ; i++ ){
            if( s[i] == 'a' ){
                la = i;
            }
            else if( (s[i] == 'b') && (fb == n) ){
                fb = i;
            }
        }
        
        return ( la < fb );
    }
};
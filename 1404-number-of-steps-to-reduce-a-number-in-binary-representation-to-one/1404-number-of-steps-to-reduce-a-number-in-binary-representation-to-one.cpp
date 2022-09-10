class Solution {
public:
    
    int solve( string& s ){
        int n = s.length();
        if( n == 1 ){
            return s[0] == '1' ? 0 : 1;
        }
        if( s[n-1] == '0' ){
            s.pop_back();
        }
        else{
            char ch = '1';
            int j = n-1;
            for( ; j >= 0 && ch == '1' ; j-- ){
                if( s[j] == '1' ){
                    s[j] = '0';
                }
                else{
                    s[j] = '1';
                    ch = '0';
                }
            }
            if( j<0 && ch == '1' ){
                reverse( s.begin(), s.end() );
                s.push_back('1');
                reverse( s.begin(), s.end() );
            }
        }
        
        return 1 + solve(s);
    }

    int numSteps(string s) {
        return solve(s);
    }
};
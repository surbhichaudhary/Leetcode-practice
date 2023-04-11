class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for( int i = 0 ; i < s.length() ; i++ ){
            if( s[i] == 'c' ){
                if( stk.size() < 2 || stk.top() != 'b' ){
                    return false;
                }
                stk.pop();
                if( stk.top() != 'a' ){
                    return false;
                }
                stk.pop();
            }
            else{
                stk.push( s[i] );
            }
        }
        return ( stk.empty() );
    }
};
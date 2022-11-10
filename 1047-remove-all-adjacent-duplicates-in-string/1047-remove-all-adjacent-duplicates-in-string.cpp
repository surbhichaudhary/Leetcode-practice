class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        for( int i=0 ;i< s.length() ; i++ ){
            if( stk.empty() || stk.top() != s[i] ){
                stk.push(s[i]);
            }
            else if( s[i] == stk.top() ){
                stk.pop();
            }
        }
        string ans = "";
        while( !stk.empty() ){
            ans.push_back(stk.top() );
            stk.pop();
        }
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};
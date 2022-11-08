class Solution {
public:
    string makeGood(string s) {
        string ans;
        
        for( int i =0 ;i < s.length() ; i++ ){
            int l = ans.length();
            if( (l>0) && (abs( s[i] - ans[l-1] ) == 32) ){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
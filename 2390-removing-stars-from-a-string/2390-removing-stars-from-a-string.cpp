class Solution {
public:
    string removeStars(string s) {
        string ans;
        
        for( int i = 0 ; i< s.length() ; i++ ){
            if( s[i] == '*' ){
                if( ans.length() > 0 ){
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
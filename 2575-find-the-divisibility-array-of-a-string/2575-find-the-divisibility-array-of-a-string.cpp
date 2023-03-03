class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long v = 0, n = word.length();
        
        for( int i = 0 ; i < n ; i++ ){
            v *= 10;
            v += (word[i]-'0');
            v %= m;
            
            if( v == 0 ){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};
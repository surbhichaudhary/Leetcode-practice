class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.length(), r = 0, c=0, i=0;
        vector<vector<char>> word( 200, vector<char>(200, 32) );
        
        while( i < n ){
            if( s[i] == 32 ){
                i++;
            }
            
            int j = i;
            while( j < n && s[j] != 32 ){
                word[j-i][c] = s[j];
                j++;
                r = max( r, j-i );
            }
            c++;
            i = j+1;
        }
        
        vector<string> ans;
        for( int i=0; i < r ;i++ ){
            string curr = "";
            
            for( int j = 0 ; j < c ; j++ ){
                curr.push_back( word[i][j] );
            }
            
            while( (curr.length() > 0) && (curr[ curr.length()-1 ] == 32) ){
                curr.pop_back();
            }
            
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};
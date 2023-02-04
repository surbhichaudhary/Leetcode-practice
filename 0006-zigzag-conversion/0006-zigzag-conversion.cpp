class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1 ) return s;
        
        int l = s.length(), c = 0, i =0 , j =0 ;
        vector<vector<char>> arr( numRows, vector<char>( l, ' ' ) );
        
        while( c < l ){
            if(j >= l ){
                j= 0;
            }
            
            if( i == 0 ){
                while( (c < l) && (i < numRows) ){
                    arr[i][j] = s[c];
                    i++;
                    c++;
                }
                i = numRows-2;
            }
            else{
                arr[i][j] = s[c];
                c++;
                i--;
            }
            j++;
        }
        
        string ans = "";
        
        for( int x = 0 ; (ans.size() < l) && (x < numRows) ; x++ ){
            for( int y =0 ; (ans.size() < l) && (y < j) ; y++ ){
                if(  isalpha( arr[x][y] ) || (arr[x][y] == ',') || (arr[x][y] == '.') ){
                    ans.push_back(arr[x][y] );
                }
            }
        }
        return ans;
    }
};
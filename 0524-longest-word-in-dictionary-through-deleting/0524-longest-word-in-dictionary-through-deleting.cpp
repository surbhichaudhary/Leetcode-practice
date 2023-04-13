class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int l = 0 ;
        string ans = "";
        
        for( int x = 0 ; x < dictionary.size() ; x++ ){
            int i =0 , j = 0, l1 = s.length(), l2 = dictionary[x].length();
            
            while( (i < l1) && (j < l2) ){
                if( s[i] == dictionary[x][j] ){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            if( j == l2 ){
                if( l2 > l ){
                    l = l2;
                    ans = dictionary[x];
                }
                else if( l2 == l && ans.compare(dictionary[x]) > 0 ){
                    ans = dictionary[x];
                }
                
            }
            
        }
        
        return ans;
    }
};
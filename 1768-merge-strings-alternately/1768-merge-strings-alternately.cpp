class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i =0, j=0, n1= word1.length(), n2 = word2.length();
        string ans ="";
        
        while( i < n1 && j < n2 ){
            ans.push_back( word1[i++] );
            ans.push_back( word2[j++] );
        }
        
        while( i < n1 ){
            ans.push_back( word1[i++] );
        }
        while( j < n2 ){
            ans.push_back( word2[j++] );
        }
        
        return ans;
    }
};
class Solution {
public:
    string reverseVowels(string s) {
        int i =0 , j = s.length()-1;
        
        unordered_map<char, int> mp;
        mp['a'] = 1 ;   mp['e'] = 1 ;   mp['A'] = 1 ;
        mp['i'] = 1 ;   mp['o'] = 1 ;   mp['E'] = 1 ;
        mp['u'] = 1 ;   mp['I'] = 1 ;   mp['O'] = 1 ;
        mp['U'] = 1 ;
        
        while( i < j ){
            if( mp.count( s[i] ) && mp.count( s[j] ) ){
                //reverse
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if( mp.count( s[i] ) && !mp.count( s[j] ) ){
                j--;
            }
            else if( !mp.count( s[i] ) && mp.count( s[j] ) ){
                i++;
            }
            else if( !mp.count( s[i] ) && !mp.count( s[j] ) ){
                i++;
                j--;
            }
        }
        
        return s;
    }
};
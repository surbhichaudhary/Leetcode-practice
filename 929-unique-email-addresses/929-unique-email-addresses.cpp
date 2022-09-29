class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string , int> mp;
        
        for( int i = 0 ; i < emails.size() ; i++ ){
            string curr = "";
            int j = 0, l = emails[i].length() ;
            
            while( j < l && emails[i][j] != '+' && emails[i][j] != '@' ){
                if( isalpha( emails[i][j] ) ){
                    curr.push_back( emails[i][j] );
                }
                j++;
            }
            if( emails[i][j] == '+' ){
                while( emails[i][j] != '@' ){
                    j++;
                }
            }
            curr += ( emails[i].substr(j) );
            mp[curr] = 1;
        }
        
        return mp.size();
    }
};
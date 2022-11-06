class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string, int> mp;
        
        for( int i =0 ; i <  startWords.size() ; i++ ){
            vector<int> freq( 26, 0 );
            
            for( int j =0 ; j <  startWords[i].length() ; j++ ){
                freq[ startWords[i][j] - 'a' ]++;
            }
            
            for( int j = 0 ; j <  26 ; j++ ){
                if( freq[j] == 0 ){
                    string curr = startWords[i];
                    char c = 'a' + j;
                    curr.push_back(c);
                    
                    sort( curr.begin(), curr.end() );
                    mp[curr]++;
                }
            }
            
        }
        
        int ans = 0;
        for( int i =0 ; i <  targetWords.size() ; i++ ){
            string curr = targetWords[i];
            sort( curr.begin(), curr.end() );
            
            if( mp.count(curr) ){
                ans++;
            }
            
        }
        
        return ans;
    }
};
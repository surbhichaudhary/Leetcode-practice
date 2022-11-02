typedef pair<int, string> si;

class Solution {
public:
    
    bool diff( string& a, string& b ){
        int c =0 , n = a.length();
        if( a.length() != b.length() ){
            return false;
        }
        
        for( int i =0 ; i < n ; i++ ){
            if( a[i] != b[i] ){
                c++;
            }
        }
        
        return ( c == 1 );
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string> > mp;
        //make graph of valid mutation
        for( int i = 0 ; i < wordList.size() ; i++ ){
            for( int j = i+1 ; j < wordList.size() ; j++ ){
                if( diff( wordList[i], wordList[j] ) ){
                    mp[ wordList[i] ].push_back( wordList[j] );
                    mp[ wordList[j] ].push_back( wordList[i] );
                }
            }
        }
        
        unordered_map<string , bool> vis;
        priority_queue<si, vector<si>, greater<si> > q;
        //priority queue is taken to get minimum number of words to reach end
        for( int i = 0 ; i < wordList.size() ; i++){
            vis[wordList[i]] = false;
            if( diff( beginWord, wordList[i] ) ){
                q.push({ 2, wordList[i] }); 
            }
        }
        
        while( !q.empty() ){
            si tp = q.top();
            q.pop();
            
            if( tp.second == endWord ){
                return tp.first;
            }
            if( vis[tp.second] ){
                continue;
            }
            vis[tp.second] = true;
            
            for( auto i : mp[tp.second] ){
                if( !vis[i] ){
                    q.push({ tp.first + 1, i });
                }
            }
        }
        
        return 0;
    }
};

class TrieNode{
    public:
        char data;
        TrieNode* child[26];
        bool isEnd;
        string word;

        TrieNode( char ch ){
            data = ch;
            for( int i=0; i<26; i++ ){
                child[i] = NULL;
            }
            isEnd = false;
        }
};

class Solution {
    public:
    
    int n,m;
    unordered_map<string, int> mp;
    vector<string> ans;
    TrieNode* root = new TrieNode('#') ;
    
    void search( int i, int j, TrieNode* curr, vector<vector<char>>& board, 
               vector<vector<bool>>& vis){
        if( i<0 || (i >= n) || j<0 || (j >= m) || vis[i][j] || (curr == NULL) ||
           (board[i][j] != curr->data) ){
            return;
        }
        
        if( curr->isEnd ){
            ans.push_back(curr->word );
            curr->isEnd = false;
        }
        
        vis[i][j] = true;
        
        for( int x = 0 ; x < 26 ; x++ ){
            if( curr->child[x] != NULL ){
                search( i-1, j, curr->child[x], board, vis );
                search( i+1, j, curr->child[x], board, vis );
                search( i, j-1, curr->child[x], board, vis );
                search( i, j+1, curr->child[x], board, vis );
            }
        }
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        ans.clear();
        for( int i = 0 ; i < words.size() ; i++ ){
            TrieNode* curr = root;
            for( int j = 0; j < words[i].length(); j++ ){
                if( curr->child[words[i][j]-'a'] == NULL ){
                    curr->child[words[i][j]-'a'] = new TrieNode(words[i][j]);
                }
                curr = curr->child[words[i][j]-'a'];
            }
            curr->isEnd = true;
            curr->word = words[i];
        }

        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis( n, vector<bool>( m, false ) );
        
        for( int i = 0 ; i<n ; i++ ){
            for( int j = 0 ; j<m ; j++ ){
                TrieNode* curr = root;
                
                if( (curr->child[board[i][j]-'a'] != NULL) ){
                    curr = curr->child[board[i][j]-'a'];
                    search( i, j, curr, board, vis );
                }
            }
        }
        
        return ans;

    }
};

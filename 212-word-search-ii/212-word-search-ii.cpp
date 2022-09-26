class TrieNode{
    public:
        char data;
        TrieNode* child[26];
        bool isEnd;

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
    TrieNode* root = new TrieNode('#') ;
    
    void search( int i, int j, TrieNode* curr, string& in, vector<vector<char>>& board, 
               vector<vector<bool>>& vis){
        if( i<0 || i >= n || j<0 || j >= m || vis[i][j] || curr == NULL ||
           board[i][j] != curr->data ){
            return;
        }
        
        in.push_back(curr->data);
        //cout<<in<<endl;
        if( curr->isEnd ){
            mp[in]=1;
        }
        
        vis[i][j] = true;
        
        for( int x = 0 ; x < 26 ; x++ ){
            if( curr->child[x] != NULL ){
                search( i-1, j, curr->child[x], in, board, vis );
                search( i+1, j, curr->child[x], in, board, vis );
                search( i, j-1, curr->child[x], in, board, vis );
                search( i, j+1, curr->child[x], in, board, vis );
            }
        }
        in.pop_back();
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        mp.clear();
        for( int i = 0 ; i < words.size() ; i++ ){
            TrieNode* curr = root;
            for( int j = 0; j < words[i].length(); j++ ){
                if( curr->child[words[i][j]-'a'] == NULL ){
                    curr->child[words[i][j]-'a'] = new TrieNode(words[i][j]);
                }
                curr = curr->child[words[i][j]-'a'];
            }
            curr->isEnd = true;
        }

        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis( n, vector<bool>( m, false ) );
        
        for( int i = 0 ; i<n ; i++ ){
            for( int j = 0 ; j<m ; j++ ){
                TrieNode* curr = root;
                
                if( curr->child[board[i][j]-'a'] != NULL ){
                    string in = "";
                    curr = curr->child[board[i][j]-'a'];
                    search( i, j, curr, in, board, vis );
                }
            }
        }
        
        vector<string> ans;
        for( auto i : mp ){
            ans.push_back(i.first);
        }

        return ans;

    }
};


class TrieNode{
    public:
    
    char data;
    TrieNode* child[26];
    bool isEnd;

    TrieNode( char c ){
        data = c;
        isEnd = false;
        for( int i = 0 ; i < 26 ; i++ ){
            child[i] = NULL;
        }
    }
};


class Trie {
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode('#');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < word.size() ){
            int ind = word[i]-'a';
            
            if( curr->child[ind] == NULL ){
                curr->child[ind] = new TrieNode( word[i] );
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < word.size() ){
            int ind = word[i]-'a';
            
            if( curr->child[ind] == NULL ){
                return false;
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        return( curr->isEnd );
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < prefix.size() ){
            int ind = prefix[i]-'a';
            
            if( curr->child[ind] == NULL ){
                return false;
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
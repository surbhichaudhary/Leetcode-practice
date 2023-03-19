class TrieNode{
    public:
    char data;
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode( char ch ){
        data = ch;
        for( int i=0 ; i < 26 ; i++ ){
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class WordDictionary {
    public:
    TrieNode* root ;
    WordDictionary() {
        root = new TrieNode('#') ;
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for( int i=0; i<word.length(); i++ ){
            if( curr->child[word[i]-'a'] == NULL ){
                curr->child[word[i]-'a'] = new TrieNode(word[i]);
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool searchUtil( int i, string& word, TrieNode* curr ){
        if( i >= word.length() ){
            return curr->isEnd;
        }
        if( word[i] != '.' && curr->child[word[i]-'a'] == NULL ){
            return false;
        }
        if( word[i] == '.' ){
            for( int j=0; j<26 ; j++ ){
                if( curr->child[j] != NULL && searchUtil(i+1, word, curr->child[j] ) ){
                    return true;
                }
            }
            return false;
        }
        curr = curr->child[word[i]-'a'];
        return searchUtil(i+1, word, curr );
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return searchUtil(0, word, curr);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
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
    
    TrieNode* root = new TrieNode('#') ;
    
public:
    
    void insert( string& word) {
        TrieNode* curr = root;
        for( int i = 0 ; i < word.length() ; i++ ){
            if( curr->child[word[i]-'a'] == NULL ){
                curr->child[word[i]-'a'] = new TrieNode(word[i] );
            }
            curr = curr->child[word[i]-'a'];
        }
        
        curr->isEnd = true;
    }
    
    int startsWith( string& prefix ) {
        TrieNode* curr = root;
        for( int i=0; i< prefix.length(); i++ ){
            if( curr->child[prefix[i]-'a'] == NULL ){
                return 0;
            }
            curr = curr->child[prefix[i]-'a'];
        }
        return 1;
    }
    
    int countPrefixes(vector<string>& words, string s) {
        insert(s);
        int ans = 0 ;
        for( int i = 0 ; i < words.size() ; i++ ){
            ans += startsWith(words[i]);
        }
        return ans;
    }
};
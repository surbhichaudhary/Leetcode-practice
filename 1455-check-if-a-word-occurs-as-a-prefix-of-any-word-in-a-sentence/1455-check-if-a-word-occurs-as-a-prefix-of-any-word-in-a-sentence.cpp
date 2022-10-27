class TrieNode{
    public:
    char data;
    int cnt;
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode( char ch ){
        data = ch;
        cnt = INT_MAX;
        for( int i=0; i<26; i++ ){
            child[i] = NULL;
        }
        isEnd = false;
    }
};
class Solution {
    
    TrieNode* root = new TrieNode('#') ;
    
public:
    
    void insert( string& word, int x) {
        TrieNode* curr = root;
        for( int i = 0 ; i < word.length() ; i++ ){
            if( curr->child[word[i]-'a'] == NULL ){
                curr->child[word[i]-'a'] = new TrieNode(word[i] );
            }
            curr = curr->child[word[i]-'a'];
            curr->cnt = min( curr->cnt, x);
        }
        
        curr->isEnd = true;
    }
    
    int startsWith( string& prefix ) {
        TrieNode* curr = root;
        for( int i=0; i< prefix.length(); i++ ){
            if( curr->child[prefix[i]-'a'] == NULL ){
                return -1;
            }
            curr = curr->child[prefix[i]-'a'];
        }
        return curr->cnt;
    }
    
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), i = 0, ind = 1;
        while( i < n ){
            string curr = "";
            int j = i;
            while( j < n && sentence[j] != 32 ){
                curr += sentence[j];
                j++;
            }
            
            insert( curr, ind );
            i = j+1;
            ind++;
        }
        return startsWith(searchWord);
    }
};
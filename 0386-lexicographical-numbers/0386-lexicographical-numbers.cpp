class TrieNode{
    public:
    char val;
    TrieNode* child[10];
    bool isEnd;
    
    TrieNode( char v ){
        val = v;
        for( int i = 0 ; i < 10 ; i++ ){
            child[i] = NULL;
        }
        isEnd = false;
    }
    
};

class Solution {
    
    TrieNode* root = new TrieNode('#') ;
    vector<int> ans;
    
public:
    
    void insert( string& word) {
        TrieNode* curr = root;
        
        for( int i = 0 ; i < word.length() ; i++ ){
            if( curr->child[word[i]-'0'] == NULL ){
                curr->child[word[i]-'0'] = new TrieNode(word[i]);
            }
            curr = curr->child[word[i]-'0'];
        }
        //cout<<word<<endl;
        curr->isEnd = true;
    }
    
    void dfs( TrieNode* curr, int num ){
        if( curr == NULL ){
            return;
        }
     
        num *= 10;
        num += (curr->val - '0');
       
        if( curr->isEnd == true ){
            //cout<<num<<endl;
            ans.push_back(num);
        }
        
        for( int i = 0 ; i< 10 ; i++ ){
            if( curr->child[i] != NULL ){
                dfs( curr->child[i], num );
            }
        }
        return;
    }
    
    vector<int> lexicalOrder(int n) {
 
        for( int i = 1 ; i <= n ; i++ ){
            string word = to_string(i);
            insert( word );
        }
        
        ans.clear();
        for( int i = 0 ; i < 10 ; i++ ){
            if( root->child[i] != NULL ){
                dfs( root->child[i], 0 );
            }
        }
        
        
        return ans;
    }
};
/*
    
    
    bool search(string word) {
        TrieNode* curr = root;
        for( int i=0; i<word.length(); i++ ){
            if( curr->child[word[i]-'a'] == NULL ){
                return false;
            }
            curr = curr->child[word[i]-'a'];
        }
        return curr->isEnd;
    }*/
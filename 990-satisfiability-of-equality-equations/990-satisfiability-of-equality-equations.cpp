class Solution {
public:
    
    vector<int> par;
    vector<int> rank;
    
    int find( int c ){
        if( par[c] == c ){
            return c;
        }
        int p = find( par[c] );
        par[c] = p;
        return p;
    }
    
    void concat( int a, int b ){
        int pa = find(a);
        int pb = find(b);
        
        if( pa != pb ){
            if( rank[pa] > rank[pb] ){
                par[pb] = pa;
            }
            else if( rank[pa] < rank[pb] ){
                par[pa] = pb;
            }
            else{
                par[pa] = pb;
                rank[pb]++;
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> neq;
        
        for( int  i=0; i< 26; i++ ){
            par.push_back(i);
            rank.push_back(1);
        }
        
        for( int i = 0 ; i < equations.size() ; i++ ){
            char a = equations[i][0], b = equations[i][3];
            if( equations[i][1] == '=' ){ //when equal
                concat( a-'a', b-'a' );
            }
            else{
                neq.push_back(i);
            }
        }
        for( int i = 0 ; i < neq.size() ; i++ ){
            char a = equations[neq[i]][0], b = equations[neq[i]][3];
            int pa = find( a-'a'), pb = find( b-'a');
            if( pa == pb ){
                return false;
            }
        }
        
        return true;
    }
};
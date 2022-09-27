class Solution {
public:
    string pushDominoes(string& dominoes) {
        
        int n = dominoes.size();
        vector<int> l( n, INT_MAX );
        vector<int> r( n, INT_MAX );
        
        queue< int > qr;
        queue< int > ql;
        
        for( int i=0; i<dominoes.size() ;i++ ){
            if( dominoes[i] == 'R' ){
                r[i] = 0;
                qr.push(i);
            }
            else if( dominoes[i] == 'L' ){
                l[i] = 0;
                ql.push(i);
            }
        }
        while( !ql.empty() ){
            int i = ql.front();
            ql.pop();
            
            if( i > 0 && dominoes[i-1] == '.' && 1+l[i] < l[i-1] ){
                l[i-1] = 1 + l[i];
                ql.push(i-1);
            }
        }
        while( !qr.empty() ){
            int i = qr.front();
            qr.pop();
            
            if( i < n-1 && dominoes[i+1] == '.' && 1 + r[i] < r[i+1] ){
                r[i+1] = 1 + r[i];
                qr.push(i+1);
            }
        }
        
        for( int i =0; i<n ;i++ ){
            if( l[i] < r[i] ){
                dominoes[i] = 'L';
            }
            else if( l[i] == r[i] ){
                dominoes[i] = '.';
            }
            else{
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
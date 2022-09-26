class Solution {
public:
    
    unordered_map<string, int> mp;
    
    void solve( int i, string& out, string& in ){
        if( i == in.length() ){
            //cout<<in<<" "<<out<<endl;
            if( out.length() > 0 ){
                mp[out]++;
            }
            return;
        }
        
        out.push_back(in[i]);
        solve( i+1, out, in );
        out.pop_back();
        solve( i+1, out, in);
        
        for( int j = i+1; j < in.length() ; j++ ){
            swap( in[i], in[j] );
            
            out.push_back(in[i]); 
            solve( i+1, out, in );
            out.pop_back();
            
            solve( i+1, out, in );
            
            swap( in[i], in[j] );
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        mp.clear();
        string out = "";
        solve( 0, out, tiles );
        return mp.size();
    }
};
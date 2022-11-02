typedef pair<string, int> si;

class Solution {
public:
    
    bool diff( string& a, string& b ){
        int c =0 ;
        
        for( int i =0 ; i < 8 ;i++ ){
            if( a[i] != b[i] ){
                c++;
            }
        }
        
        return ( c <= 1 );
    }
    
    
    int minMutation(string start, string end, vector<string>& bank) {
        if( start == end ){
            return 0;
        }
        if( diff(start, end) ){ // when start and end differ by one char
            bool flag = false; // to ensure end is a valid mutation
            for( int i = 0 ;i < bank.size() ; i++ ){
                if( bank[i] == end ){
                    flag = true;
                    break;
                }
            }
            return ( flag ? 1 : -1 );
        }
        
        unordered_map<string, vector<string> > mp;
        //make graph of valid mutation
        for( int i = 0 ; i < bank.size() ; i++ ){
            for( int j = i+1 ; j < bank.size() ; j++ ){
                if( diff( bank[i], bank[j] ) ){
                    mp[bank[i]].push_back(bank[j]);
                    mp[bank[j]].push_back(bank[i]);
                }
            }
        }
        
        unordered_map<string , bool> vis;
        priority_queue<si, vector<si>, greater<si> > q;
        for( int i = 0 ;i < bank.size() ; i++){
            vis[bank[i]] = false;
            if( diff( start, bank[i] ) ){
                q.push( {bank[i], 1} ); 
            }
        }
        
        while( !q.empty() ){
            si tp = q.top();
            q.pop();
            vis[tp.first] = true;
            
            if( tp.first == end ){
                return tp.second;
            }
            
            for( auto i : mp[tp.first] ){
                if( !vis[i] ){
                    q.push({ i, tp.second + 1 });
                }
            }
        }
        
        return (-1);
    } 
};


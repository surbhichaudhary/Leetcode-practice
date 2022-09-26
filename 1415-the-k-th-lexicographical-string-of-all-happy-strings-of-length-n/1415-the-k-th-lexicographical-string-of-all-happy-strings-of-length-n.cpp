class Solution {
public:
    
    unordered_map<string, int > mp;
    
    void solve( int& n, string& in ){
        if( in.length() == n ){
            //cout<<in<<endl;
            mp[in]++;
            return;
        }
        
        if( in.length() == 0 ){
            in.push_back('a');
            solve( n, in );
            in.pop_back();
            
            in.push_back('b');
            solve( n, in );
            in.pop_back();
            
            in.push_back('c');
            solve( n, in );
            in.pop_back();
            return;
        }
        
        int l = in.length();
        
        if( in[l-1] == 'a' ){
            in.push_back('b');
            solve( n, in );
            in.pop_back();
            
            in.push_back('c');
            solve( n, in );
            in.pop_back();
            return;
        }
        else if( in[l-1] == 'b' ){
            in.push_back('a');
            solve( n, in );
            in.pop_back();
            
            in.push_back('c');
            solve( n, in );
            in.pop_back();
            return;
        }
        
        in.push_back('b');
        solve( n, in );
        in.pop_back();

        in.push_back('a');
        solve( n, in );
        in.pop_back();
        return;
    } 
    
    string getHappyString(int n, int k) {
        mp.clear();
        string in="";
        solve(n, in);
        
        if( mp.size() >= k) {
            vector<string> ans;
            for( auto i : mp ){
                ans.push_back(i.first);
            }
            sort( ans.begin(), ans.end() );
            return ans[k-1];
        }
        return "";
    }
};
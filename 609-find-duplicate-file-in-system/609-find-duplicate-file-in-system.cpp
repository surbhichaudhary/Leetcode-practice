class Solution {
public:
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string>> ans;
        
        for( int i = 0 ; i < paths.size() ; i++ ){
            string tmp = "";
            int j = 0, n = paths[i].length();
            while( j < n && paths[i][j] != 32 ){
                tmp.push_back(paths[i][j]);
                j++;
            }
            //file content reached;
            while( j < n ){
                int k = j+1;
                
                string p1 = tmp;
                p1.push_back('/');
                while( k < n && paths[i][k] != '(' ){
                    p1.push_back( paths[i][k] );
                    k++;
                }
                
                string content = "";
                k++;
                while( k < n && paths[i][k] != ')' ){
                    content.push_back( paths[i][k] );
                    k++;
                }
                
                mp[content].emplace_back(p1);
                j = k+1 ;
            }
        }
        
        for( auto i : mp ){
            if( i.second.size() > 1 ){
                ans.emplace_back(i.second);
            }
        }
        return ans;
    }
};
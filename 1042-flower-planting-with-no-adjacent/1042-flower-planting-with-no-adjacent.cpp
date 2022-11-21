class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> mp;
      
        for( int i = 0 ; i < paths.size(); i++ ){
            int u = paths[i][0], v = paths[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<int> colour(n,0);
        
        for( int i = 0; i < n ; i++ ){
            if( colour[i] == 0 ){
                //find which all colours neighbours have
                unordered_set<int> s;
                for( auto j : mp[i+1] ){
                    s.insert( colour[j-1] );
                }
                
                for( int j = 1 ; j <= 4 ; j++ ){
                    if( s.find(j) == s.end() ){ 
                        // assign this colour to j
                        colour[i] = j;
                        break;
                    }
                }
                //colour has been asssigned to i
            }
        }
        return colour;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        vector<int> indeg( n, 0 );
        
        for( int i  =0 ; i< edges.size() ; i++ ){
            mp[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        queue<int> bfs;
        vector<int> ans;
        vector<bool> vis( n, false );
        
        for( int i =0 ; i<n ; i++ ){
            if( indeg[i] == 0 ){
                bfs.push(i);
                ans.push_back(i);
            }
        }
        
        while( !bfs.empty() ){
            int fr = bfs.front();
            bfs.pop();
            
            if( vis[fr] ){
                continue;
            }
            
            vis[fr] = true;
            for( auto i : mp[fr] ){
                if( !vis[i] ){
                    bfs.push(i);
                }
            }
            
        }
        
        for( int i =0 ; i < n ; i++ ){
            if( !vis[i] ){
                ans.push_back(i);
            } 
        }
        
        return ans;
    }
};


class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        unordered_map<int, vector<int>> neigh;
        unordered_map<int, unordered_set<int>> edge;
        
        vector<bool> vis(n, false);
        
        for( int i = 0 ; i < connections.size() ; i++ ){
            int a = connections[i][0], b = connections[i][1];
            
            neigh[a].push_back(b);
            neigh[b].push_back(a);
            
            edge[a].insert(b);
        }
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while( !q.empty() ){
            int fr = q.front();
            q.pop();
            
            for( auto i : neigh[fr] ){
                if( vis[i] ){
                    continue;
                }
                if( !edge.count(i) || ( edge[i].find(fr) == edge[i].end()) ){
                    edge[i].insert(fr);
                    ans++;
                }
                
                q.push(i);
                vis[i] = true;
            }
        }
        
        return ans;
    }
};

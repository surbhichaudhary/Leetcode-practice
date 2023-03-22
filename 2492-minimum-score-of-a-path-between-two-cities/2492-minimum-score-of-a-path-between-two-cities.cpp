typedef pair<int, int> pi;

class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<int> dist( n+1, INT_MAX );
        unordered_map< int, vector< pi > > mp;
        
        for( int i = 0 ; i < roads.size() ; i++ ){
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            
            mp[u].push_back({ v, w });
            mp[v].push_back({ u, w });
            
        }
        
        queue< int > pq;
 
        for( auto i : mp[1] ){
            ans = min( ans, i.second );
            dist[i.first] = i.second;
            pq.push(i.first);
        }
        
        while( !pq.empty() ){
            int u = pq.front();
            pq.pop();
            
//             if( u == n ){
//                 ans = min( ans, dist[u] );
//                 continue;
//             }
          
            for( auto i : mp[u] ){
                int d = min( dist[u], i.second );
                ans = min( min( d, ans ), i.second );
                if( d < dist[i.first] ){
                    dist[i.first] = d;
                    pq.push(i.first);
                }
            }
        }
        
        return ans;
    }
};

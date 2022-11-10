typedef pair<int, int> pi;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //point1 - { point2, dist }
        unordered_map< int, vector<pi> > mp;
        int n = points.size(), ans=0;
        
        for( int i = 0 ; i < n ; i++ ){
            int x1 = points[i][0], y1 = points[i][1];
            
            for( int j = i+1 ;j < n ;j++ ){
                int x2 = points[j][0], y2 = points[j][1], d = abs(x1 - x2) + abs(y1 - y2);
                
                mp[i].push_back({ j, d });
                mp[j].push_back({ i, d });
            }
        }
        
        priority_queue< pi, vector<pi>, greater<pi> >pq;
        vector<int> dist( n, INT_MAX );
        vector< bool> vis( n, false);
        
        pq.push({ 0, 0 });
        dist[0] = 0;
        
        while( !pq.empty() ){
            int u = pq.top().second, d = pq.top().first;
            pq.pop();
            
            if( vis[u] ){
                continue;
            }
            
            vis[u] = true;
            ans += d;
    
            for( auto i : mp[u] ){
                int v = i.first, w = i.second;
                if( !vis[v] && w < dist[v] ){
                    dist[v] = w;
                    pq.push({ w, v });
                }
            }
        }
        
        return ans;
    }
};
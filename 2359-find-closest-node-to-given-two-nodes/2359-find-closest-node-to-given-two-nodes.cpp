class Solution {
public:
    
    unordered_map<int, int> mp;
    
    void bfs( int node, vector<int>& dist ){
        queue<int> q;
        q.push(node);
        vector<bool> visit( dist.size(), false );
        dist[node] = 0;
        
        while( !q.empty() ){
            int fr = q.front();
            q.pop();
            
            if( !mp.count(fr) || visit[fr] ){
                continue;
            }
            
            visit[fr] = true;
            int adj = mp[fr];
            dist[adj] = min( dist[adj], 1 + dist[fr]);
            q.push(adj);
        }
        
        return;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        mp.clear();
        
        int n = edges.size(), m = INT_MAX, ans = m, pos = -1;
        for( int i = 0 ; i < n ; i++ ){
            if( edges[i] != -1 ){
                mp[i] = edges[i];
            }
        }
        //call bfs for node 1
        vector<int> dist1( n, m );
        bfs( node1, dist1 );
        
        //call bfs for node 2
        vector<int> dist2( n, m );
        bfs( node2, dist2 );
        
        for( int i = 0 ; i< n; i++ )
        {
            if( dist1[i] != m && dist2[i] != m )
            {
                if( ans > max( dist1[i], dist2[i] ) )
                {
                    ans =  max( dist1[i], dist2[i] );
                    pos = i;
                }
            }
        }
        return pos;
    }
};

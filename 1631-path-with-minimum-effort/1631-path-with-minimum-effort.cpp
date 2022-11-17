typedef pair< int, vector<int> > iv;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< iv, vector<iv> , greater<iv> > pq;
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dst( n, vector<int>( m, INT_MAX ));
        
        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, 1, 0, -1 };
        
        pq.push({ 0, {0,0} });
        
        while( !pq.empty() ){
            iv fr = pq.top();
            pq.pop();
            
            int x = fr.second[0], y = fr.second[1], e = fr.first;
            
            if( (x == n-1) && (y == m-1) ){
                return e;
            }
            
            for( int i =0 ; i < 4 ; i++ ){
                int x1 = x + dx[i], y1 = y+dy[i];
                if( (x1 >= 0) && (x1 < n) && (y1 >= 0) && (y1 < m) ){
                    int e1 = max( e, abs( heights[x][y] - heights[x1][y1] ) );
                    if( dst[x1][y1] > e1 ){
                        dst[x1][y1] = e1;
                        pq.push({ e1, { x1, y1 } });
                    }
                }
            }
            
        }
        return dst[n-1][m-1];
    }
};
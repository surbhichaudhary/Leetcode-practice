class Solution {
public:
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
        int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
        
        vector<vector<bool>> q( 8, vector<bool>( 8, false));
        for( int i=0; i< queens.size() ; i++ ){
            int x = queens[i][0], y = queens[i][1];
            q[x][y] = true;
            
        }
        
        queue< pair< vector<int>, int> > bfs;
        
        for( int i = 0 ; i < 8 ; i++ ){
            int x = king[0] + dx[i];
            int y = king[1] + dy[i];
            
            if( (x >=0) && (x < 8) && ( y>=0) && ( y<8) ){
                bfs.push({ {x,y}, i });
            }
            
        }
        
        vector<vector<int>> ans;
        
        while( !bfs.empty() ){
            vector<int> fr = bfs.front().first;
            int d = bfs.front().second, a =  fr[0], b = fr[1];
            bfs.pop();
            
            if( q[a][b] ){
                ans.push_back(fr);
                continue;
            }
            
            int x = fr[0] + dx[d], y = fr[1] + dy[d];
            if( (x >=0) && (x < 8) && ( y>=0) && ( y<8) ){
                bfs.push({ {x,y}, d });
            }
            
        }
        
        return ans;
        
    }
};
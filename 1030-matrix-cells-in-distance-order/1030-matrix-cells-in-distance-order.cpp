typedef pair< int, vector<int> > iv;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> mat( rows, vector<int>(cols, 0) );
        priority_queue<iv, vector<iv>, greater<iv> > pq;
        
        for( int i =0 ; i < rows ; i++ ){
            for( int j = 0 ; j < cols ; j++ ){
                mat[i][j] = abs( i - rCenter) + abs( j-cCenter );
                pq.push({ mat[i][j], {i, j} });
            }
        }
        
        vector<vector<int>> ans;
        while( !pq.empty() ){
            iv tp = pq.top();
            pq.pop(); 
            
            ans.push_back( tp.second );
        }
        
        return ans;
    }
};

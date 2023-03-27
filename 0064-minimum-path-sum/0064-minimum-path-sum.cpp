class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int arr[n][m];
        arr[n-1][m-1] = grid[n-1][m-1];
        
        for( int i =n-2; i >= 0; i-- ){
            arr[i][m-1] = grid[i][m-1]+ arr[i+1][m-1];
        }
        for( int i = m-2; i>=0; i-- ){
            arr[n-1][i] = grid[n-1][i] + arr[n-1][i+1];
        }
        
        for( int i = n-2; i>=0 ;i-- ){
            for( int j = m-2; j>=0; j-- ){
                arr[i][j] = grid[i][j] + min( arr[i+1][j], arr[i][j+1]);
            }
        }
        return arr[0][0];
    }
};
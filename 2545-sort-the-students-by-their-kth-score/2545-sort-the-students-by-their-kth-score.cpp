typedef pair< int, int > pi;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        priority_queue< pi > pq;
        vector<vector<int>> ans;
        
        for( int i =0 ;i< score.size() ; i++ ){
            pq.push({ score[i][k], i });
        }
        
        while( !pq.empty() ){
            ans.push_back( score[ pq.top().second ]);
            pq.pop();
        }
        
        return ans;
    }
};
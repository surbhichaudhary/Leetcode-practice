typedef pair<double, pair<int, int>> dt;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue< dt > pq;
        int n = arr.size();
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = i+1 ; j < n ; j++ ){
                double fr = ( (double)arr[i] )/arr[j];
                
                pq.push({ fr, { arr[i], arr[j] } });
                if( pq.size() > k ){
                    pq.pop();
                }
            }
            
        }
        vector<int> ans;
        pair<int, int> p = pq.top().second;
        
        ans.push_back( p.first );
        ans.push_back( p.second );
        
        return ans;
    }
};
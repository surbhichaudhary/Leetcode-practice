typedef pair<int,int> pi;
typedef pair<int, pi> vc;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< vc, vector<vc>, greater<vc>> pq;
        int mx = INT_MIN, mn = INT_MAX;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            pq.push( { nums[i][0], {i,0} } );
            mx = max( mx, nums[i][0] );
            mn = min( mn, nums[i][0] );
        }
        int s = mn, e = mx;
        
        while( !pq.empty() ){
            vc tp = pq.top();
            pq.pop();
            int r = tp.second.first, c = tp.second.second;
            
            mn = tp.first;
            
            if( mx-mn < e-s ){
                s = mn;
                e = mx;
            }
            
            if( c < nums[r].size()-1 ){
                mx = max( mx, nums[r][c+1] );
                pq.push({ nums[r][c+1] , { r, c+1} });
            }
            else {
                break;
            }
        }
        
        vector<int> ans;
        ans.emplace_back(s);
        ans.emplace_back(e);
        
        return ans;
    }
};
typedef pair<int, int> pi;

class Solution {
public:
    
    static bool comp( pi& a, pi& b ){
        return a.second < b.second ;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            pq.push({ nums[i], i});
            if( pq.size() > k ){
                pq.pop();
            }
        }
        
        vector<pi> sub;
        while( !pq.empty() ){
            sub.push_back(pq.top());
            pq.pop();
        }
        
        sort( sub.begin(), sub.end(), comp );
        
        vector<int> ans;
        for( int i =0; i < k ;i++ ){
            ans.push_back(sub[i].first);
        }
        
        return ans;
    }
};
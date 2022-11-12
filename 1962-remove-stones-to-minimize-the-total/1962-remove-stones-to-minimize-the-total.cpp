class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        
        for( int i = 0 ; i < piles.size() ; i++ ){
            pq.push( piles[i] );
        }
        
        while( (k > 0) && (!pq.empty()) ){
            int t = pq.top();
            pq.pop();
            int r = t/2;
            t -= r;
            pq.push(t);
            k--;
        }
        
        int ans =0 ;
        while( !pq.empty() ){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
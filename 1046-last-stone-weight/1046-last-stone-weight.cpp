class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for( int i=0; i<stones.size(); i++ ){
            pq.push(stones[i]);
        }
        
        while( pq.size() >= 2 ){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if( a == b ){
                continue;
            }
            else if( a < b){
                pq.push(b-a);
            }
            else if( b<a ){
                pq.push(a-b);
            }
        }
        if( pq.size() == 1 ){
            return pq.top();
        }
        return (0);
    }
};
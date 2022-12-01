typedef pair<int, int> pi;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue< pi, vector<pi>, greater<pi> >pq;
        int n = apples.size(), ans =0;
        
        for( int i = 0 ; i< n ; i++ ){
            if( pq.empty() )
            {
                if( apples[i] > 0 ){
                    ans++;
                    if( apples[i] > 1 ){
                        pq.push({ i+1+days[i], apples[i]-1 });
                    }
                }
            }
            else
            {
                while( (!pq.empty()) && (pq.top().first <= i+1) ){
                    pq.pop();
                }
                
                if( apples[i] > 0 ){
                    pq.push({ i+1+days[i], apples[i] });
                }
                
                if( !pq.empty() ) {
                    ans++;
                    pi tp = pq.top();
                    pq.pop();
                    tp.second -= 1;
                    if( tp.second > 0 ){
                        pq.push(tp);
                    }
                }
            }
        }
        n++;
        while( !pq.empty() ){
            
            while( (!pq.empty()) && (pq.top().first <= n ) ){
                pq.pop();
            }
            if( pq.empty() ){
                break;
            }
            
            ans++;
            pi tp = pq.top();
            pq.pop();
            tp.second -= 1;
            
            if( tp.second > 0 ){
                pq.push(tp);
            }
            n++;
        }
        
        return ans;
    }
};
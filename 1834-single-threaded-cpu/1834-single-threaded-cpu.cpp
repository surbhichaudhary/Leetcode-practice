// priority_queue<data_type, container, comparator> ds;

typedef long long ll;
typedef pair<ll, ll> pi;

class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        ll n = tasks.size();
        priority_queue< pi, vector<pi>, greater<> > pq;
        
        for( int i = 0 ; i < n ; i++ ){
            tasks[i].push_back(i);
        }
        
        sort( tasks.begin(), tasks.end() );
        ll t = tasks[0][0], i = 0;
      
        while( (!pq.empty()) || ( i < n ) ){
            
            if( pq.empty() && t < tasks[i][0] ){
                t = tasks[i][0];
            }
            
            while( (i < n) && (tasks[i][0] <= t) )
            {
                pq.push({ tasks[i][1], tasks[i][2] });
                i++;
            }
            
            pi tp = pq.top();
            pq.pop();

            ans.push_back( tp.second );
            t += tp.first;
        }
        
        return ans;
    }
};

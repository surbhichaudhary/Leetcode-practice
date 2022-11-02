class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
                          int start, int end) {
        
        unordered_map< int, vector< pair<int, double> > > mp;
        unordered_map< int, bool > vis;
        
        for( int i = 0 ; i < edges.size() ; i++ ){
            mp[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            mp[edges[i][1]].push_back({ edges[i][0], succProb[i] });
            
            vis[ edges[i][0] ] = false;
            vis[ edges[i][1] ] = false;
        }
        //probability - node
        priority_queue<pair<double, int>> pq;
        for( auto i : mp[start] ){
            pq.push({ i.second, i.first });
        }
        
        while( !pq.empty() ){
            pair<double, int> tp = pq.top();
            pq.pop();
         
            if( tp.second == end ){
                return tp.first;
            }
            
            if( vis[tp.second] ){
                continue;
            }
            vis[tp.second] = true;
            
            for( auto i : mp[tp.second] ){
                double p1 = tp.first, p2 = i.second, p3 = log10(p1) + log10(p2);
                double p = pow( 10, p3 );
                //cout<<tp.second<<" "<<i.first<<" "<<p<<endl;
                pq.push({ p, i.first });
            }
            
        }
        
        return ( 0.0 );
        
    }
};
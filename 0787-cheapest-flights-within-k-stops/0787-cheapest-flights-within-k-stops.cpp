typedef pair<int, int> pi;
typedef vector<pi> vp;
typedef vector<int> vi;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        unordered_map< int, vp > mp;
        for( int i = 0 ; i < flights.size() ; i++ ){
            int u = flights[i][0], v = flights[i][1], p = flights[i][2];
            mp[u].push_back({ v, p });
        }
        
        vi dist( n, INT_MAX );
        queue< pi> q;
        q.push({ src, 0 });
        int st = 0;
        
        while( ( st <= k ) && !q.empty() ){
            int s = q.size();
            while( s-- ){
                pi fr = q.front();
                q.pop();
                
                for( auto i : mp[fr.first] ){
                    int p = i.second, v = i.first;
                    
                    if( p + fr.second >= dist[v] ){
                        continue;
                    }
                    dist[v] = p + fr.second;
                    q.push({ v, dist[v] });
                    
                }
            }
            st++;
        }
        
        return (( dist[dst] < INT_MAX )? dist[dst] : -1 );
        
    }
};
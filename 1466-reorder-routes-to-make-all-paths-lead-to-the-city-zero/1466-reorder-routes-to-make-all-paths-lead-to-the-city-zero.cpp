class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map< int, unordered_set<int> > out;
        unordered_map< int, unordered_set<int> > in;
        vector<int> path( n, false );
        path[0] = true;
        int ans = 0;
        queue<int> q;
        q.push(0);
        
        for( int i = 0 ; i < connections.size() ; i++ ){
            out[ connections[i][0] ].insert( connections[i][1] );
            in[ connections[i][1] ].insert( connections[i][0] );
        }
        
        while( !q.empty() ){
            int fr = q.front();
            q.pop();
            
            for( auto i : in[fr] ){// edge i->fr
                if( !path[i] ){
                    path[i] = true;
                    q.push(i);
                }
            }
            for( auto i : out[fr] ){ //edge fr->i
                if( !path[i] ){
                    ans++;
                    path[i] = true;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if( x == 0 )
            return 0;
        
        unordered_map<int , int> mp;
        for( int i = 0 ; i < forbidden.size() ; i++ ){
            mp[forbidden[i]]++;
            
            if( (forbidden[i] == 0) || (forbidden[i] == a) )
                return (-1);
        }
        
        queue<vector<int>> q;
        vector<bool> vis( 10000, false );
        // position - step - direction 
        q.push({ a, 1, 0 });
        //direction == 0 means can jump backward;
        while( !q.empty() ){
            int s = q.size();
            for( int i = 0 ; i < s ; i++ ){
                vector<int> fr = q.front();
                q.pop();
                
                if( fr[0] == x ){
                    return fr[1];
                }
                
                vis[fr[0]] = true;
                int bck = fr[0]-b, frw = fr[0] + a;
                
                if( (bck > 0) && (bck < 10000) && !vis[bck] && (fr[2] == 0) &&
                   !mp.count(bck) ){
                    vis[bck] = true;
                    q.push({ bck, fr[1]+1, 1 });
                }
                if( (frw > 0) && (frw < 10000) && !vis[frw] && !mp.count(frw) ){
                    vis[frw] = true;
                    q.push({ frw, fr[1]+1, 0 });
                }
            }
        }
        
        return (-1);
    }
};
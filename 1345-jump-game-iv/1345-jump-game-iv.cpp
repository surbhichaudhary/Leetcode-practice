class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        unordered_map< int, vector<int> > mp;
        int n = arr.size(), ans = 0;
        if( n <= 2 ){
            return n-1; 
        }
        
        for( int i = 0 ; i < n ; i++ ){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        vector<int> time( n, INT_MAX );
        time[0] = 0;
        
        while( !q.empty() ){
            int s = q.size();
            
            for( int i = 0 ; i < s ; i++ ){
                int fr = q.front();
                q.pop();

                if( fr == n-1 )
                    return ans;

                if( (fr > 0) && (time[fr-1] == INT_MAX) ){
                    time[fr-1] = 1+time[fr];
                    q.push(fr-1);
                }
                if( (fr < n-1) && (time[fr+1] == INT_MAX) ){
                    time[fr+1] = 1+time[fr];
                    q.push(fr+1);
                }
                if( mp.count(arr[fr]) ){
                    for( auto j : mp[arr[fr]] ){
                        if( time[j] > time[fr]+1 ){
                            q.push(j);
                            time[j] = time[fr]+1;
                        }
                    }
                }
                mp.erase( arr[fr]);
            }
            ans++;
        }
        
        return -1;
    }
};
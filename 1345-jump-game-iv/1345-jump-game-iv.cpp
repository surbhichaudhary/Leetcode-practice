class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        int n = arr.size(), ans =0;
        unordered_map< int, vector<int> > mp;
        
        for( int i = 0 ; i < n ; i++ ){
            mp[arr[i]].push_back(i);
        }
        
        vector<bool> visit( n, false);
        queue<int> q;
        q.push(0) ;
        visit[0] = true;
        
        while( !q.empty() ){
            int s = q.size();
            for( int j = 0; j < s; j++ ){
                int fr = q.front();
                q.pop();
                
                if( fr == n-1 ) return ans;
                
                if( fr-1 >= 0 && !visit[fr-1] ){
                    q.push(fr-1);
                    visit[fr-1] = true;
                }
                if( fr+1 < n && !visit[fr+1] ){
                    q.push(fr+1);
                    visit[fr+1] = true;
                }
                
                if( mp.count(arr[fr]) ){
                    for( auto k : mp[arr[fr]] ){
                        if( !visit[k] ){
                            q.push(k);
                            visit[k] = true;
                        }
                    }
                    mp.erase(arr[fr]);
                }
            }
            ans++;
        }
        
        return -1;
        
    }
};


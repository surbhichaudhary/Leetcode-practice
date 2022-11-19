class Solution {
public:
    
    bool DFS( int node, unordered_set<int>& s, vector<bool>& vis, 
             vector<bool>& safe, vector<vector<int>>& graph )
    {
        if((s.find( node ) != s.end()) || (vis[node] && !safe[node] )){
            return false;
        }
        if( vis[node] && safe[node] ){
            return true;
        }
        
        vis[node] = true;
        s.insert(node);
        
        bool ans = true;
        for( int i = 0;  i < graph[node].size() ; i++ ){
            if( vis[graph[node][i]] && safe[graph[node][i]] ){
                continue;
            }
            if( !DFS( graph[node][i], s, vis, safe, graph ) ){// not safe 
                ans = false;
                break;
            }
        }
        safe[node] = ans;
        return ans;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<bool> safe( n, false);
        vector<bool> vis( n, false);
        vector<int> ans;
        
        for( int i =0 ;i < n ;i++ ){
            if( graph[i].size() == 0 ){
                safe[i] = true;
                vis[i] = true;
            }
        }
        
        for( int i = 0 ; i < n ; i++ ){
            if( !vis[i] ){
                unordered_set<int> s;
                safe[i] = DFS( i, s, vis, safe, graph );
            }
        }
        
        for( int i = 0 ; i < n ;i++ ){
            if( safe[i] ){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

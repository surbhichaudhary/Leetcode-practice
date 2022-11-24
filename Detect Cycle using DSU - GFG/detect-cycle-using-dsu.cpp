//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find( int u, vector<int>& par ){
        if( par[u] != u ){
            par[u] = find( par[u], par );
        }
        return par[u];
    }
    
    void union_set( int a, int b, vector<int>& par, vector<int>& rank ){
      
        if( rank[a] >= rank[b] ){
            par[b] = a;
            rank[a] += rank[b];
        }
        else{
            par[a] = b;
            rank[b] += rank[a];
        }
        
        return ;
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> par( V );
	    vector<int> rank( V, 1 );
	    
	    for( int i =0 ; i < V ; i++ ){
	        par[i] = i;
	    }
	    for( int i =0 ; i < V ; i++ ){
	        for( auto j : adj[i] ){
	            int a = find( i, par), b = find( j, par);
	            if( a == b ){
	                if( j > i ){
	                    return 1;
	                }
	            }
	            union_set( a, b, par, rank );
	        }
	    }
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
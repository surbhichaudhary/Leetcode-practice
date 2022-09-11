typedef pair<int, int> pi;

class Solution {
public:
    
    static bool comp( vector<int> a, vector<int> b ){
        return a[0] < b[0] ;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> unique;
        
        for( int i = items.size()-1 ; i >= 0 ; i--){
            unique[items[i][0]] = max( unique[items[i][0]], items[i][1] );
        }
        items.clear();
        for( auto i : unique ){
            vector<int> tmp;
            tmp.push_back(i.first);
            tmp.push_back(i.second);
            items.push_back(tmp);
        }
        unique.clear();
        sort( items.begin(), items.end() );
        
        int mx = 0, n = items.size();
        for( int i = 0 ; i < items.size() ; i++ ){
            mx = max( mx, items[i][1] );
            mp[items[i][0]] = mx;
            //cout<<items[i][0]<<" "<< mp[items[i][0]]<<endl;
        }
        
        vector<int> ans;
        for( int  i = 0 ; i < queries.size() ; i++ ){
            int val = queries[i];
            
            if( val < items[0][0] ){
                ans.push_back(0);
            }
            else if( val >= items[n-1][0] ){
                ans.push_back( mp[items[n-1][0] ] );
            }
            
            else if( mp.count(val) ){
                ans.push_back( mp[val] );
            }
            else{
                int s = 0, e = n-1, b = 0;
                while( s <= e ){
                    int m = s + (e-s)/2;
                    if( items[m][0] < val ){
                        b = mp[ items[m][0] ];
                        s = m+1;
                    }
                    else{
                        e = m-1;
                    }
                }
                ans.push_back(b);
            }
            
        }
        
        return ans;
    }
};

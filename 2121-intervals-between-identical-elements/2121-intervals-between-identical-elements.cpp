class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map< int, vector<long long> > mp;
        int n = arr.size();
        
        for( int i = 0 ; i < n ; i++ ){ //O(n);
            mp[arr[i]].push_back(i);
        }
        
        vector<long long> ans(n ,0);
        
        for( auto i : mp ){
            int s = i.second.size();
            vector<long long> left( s, 0);
            vector<long long> right( s, 0);
            vector<long long> curr = i.second;
            
            for( int j = 1 ; j < s ; j++ ){
                left[j] = left[j-1] + curr[j-1];
            }
            for( int j = s-2 ; j >= 0 ; j-- ){
                right[j] = ( right[j+1] + curr[j+1] );
            }
            
            for( int j = 0 ; j < s ; j++ ){
               // cout<<i.first<<" "<<right[j]<<" "<<left[j]<<" "<<curr[j]<<endl;
                long long ls = ( curr[j] * j - left[j] );
                long long rs = ( right[j] - ( s-1-j )*curr[j] );
                ans[curr[j]] =  ls + rs;
            }
        }
        return ans;
    }
};
/*for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;*/
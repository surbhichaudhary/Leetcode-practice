class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        for( int i=0; i< changed.size(); i++ ){
            mp[changed[i]]++;
        }
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for( auto i : mp ){
            for( int j =0; j< i.second; j++ ){
                pq.push( i.first );
            }
        }
        
        while( !pq.empty() && mp.size() > 0 ){
            int mn = pq.top();
            pq.pop();
            
            if( mn == 0 && mp.find( mn ) != mp.end() && mp[mn] >= 2 ){
                ans.push_back(mn);
                mp[mn] -= 2;
                if( mp[mn] == 0 ){
                    mp.erase(mn);
                }
            }
            else if( mp.find( mn ) != mp.end() && mp.find(2 * mn ) != mp.end() ){
                ans.push_back(mn);
                mp[mn]--;
                if( mp[mn] == 0 ){
                    mp.erase(mn);
                }
                mp[2*mn]--;
                if( mp[2*mn] == 0 ){
                    mp.erase(2*mn);
                }
            }
        }
        
        if( mp.size() > 0 ){
            ans.clear();
        }
        return ans;
    }
};
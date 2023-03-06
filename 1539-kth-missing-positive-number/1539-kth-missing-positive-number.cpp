class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for( int i = 0; i < arr.size() ;i++ ){
            mp[arr[i]]++;
        }
        
        priority_queue<int> pq;
        int curr = 1;
        while( pq.size() < k ){
            if( !mp.count(curr) ){
                pq.push(curr);
            }
            curr++;
        }
        return pq.top();
    }
};
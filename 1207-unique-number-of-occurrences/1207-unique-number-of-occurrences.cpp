class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_map<int, int> cnt;
        
        for( int i = 0 ;i < arr.size() ; i++ ){
            freq[arr[i]]++;
        }
        
        for( auto i : freq ){
            if( cnt.find(i.second) != cnt.end() ){
                return false;
            }
            cnt[i.second]++;
        }
        return true;
    }
};
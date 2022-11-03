class Solution {
public:
    
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> e1;
        vector<int> o1;
        vector<int> e2;
        vector<int> o2;
        
        for( int i =0 ; i< nums.size() ; i++ ){
            if( nums[i]%2 == 0 ){
                e1.push_back( nums[i] );
            }
            else{
                o1.push_back( nums[i] );
            }
            
            if( target[i]%2 == 0 ){
                e2.push_back( target[i] );
            }
            else{
                o2.push_back( target[i] );
            }
        }
        
        sort( e1.begin(), e1.end() );
        sort( e2.begin(), e2.end() );
        sort( o1.begin(), o1.end() );
        sort( o2.begin(), o2.end() );
        
        long long res = 0;
        for(int i=0 ; i < e1.size() ; i++)
            res += abs( e1[i] - e2[i] );
        
        for(int i=0 ; i < o1.size() ; i++)
            res += abs( o1[i]- o2[i] );
        
        res/=4;
        
        return res;
        
    }
};


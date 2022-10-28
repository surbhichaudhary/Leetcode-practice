class Solution {
public:
    
    vector<string> removeAnagrams(vector<string>& words) {
        set<int> s;
        int n = words.size();
        
        for( int i = 0 ; i < n ; i++ ){
            s.insert(i);
        }
        
        int i = 0, j = 1;
        while( i < n && j < n ){
            if( s.find(i) != s.end() && s.find(j) != s.end() ){
                string s1 = words[i], s2 = words[j];
                sort( s1.begin(), s1.end() );
                sort( s2.begin(), s2.end() );
                
                if( s1 == s2 ){
                    s.erase(j);
                    j++;
                }
                else{
                    i++;
                }
            }
            
            while( i < n && s.find(i) == s.end() ){
                i++;
            }
            while( j < n && s.find(j) == s.end() ){
                j++;
            }
            
            if( i == j ){
                j++;
            }
        }
        
        vector<string> ans;
        for( auto i : s ){
            ans.push_back( words[i] );
        }
        
        return ans;
    }
};
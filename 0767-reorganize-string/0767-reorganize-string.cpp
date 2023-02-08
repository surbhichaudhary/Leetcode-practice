typedef pair< int, char > ic;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map< char, int > mp;
        string ans = "";
        for( int i = 0 ; i < s.length() ; i++ ){
            mp[s[i]]++;
        }
        
        priority_queue< ic > pq;
        for( auto i : mp ){
            pq.push({ i.second, i.first });
        }
        
        while( !pq.empty() ) {
            ic tp1 = pq.top();
            pq.pop();
            int l = ans.length();

            if( !pq.empty() ){
                ic tp2 = pq.top();
                pq.pop();
                
                if( l > 0 ){
                    if( ans.back() != tp1.second ){
                        ans.push_back(tp1.second);
                        ans.push_back(tp2.second);

                        tp1.first--;
                        tp2.first--;
                    }
                    else {
                        ans.push_back(tp2.second);
                        ans.push_back(tp1.second);
                        
                        tp1.first--;
                        tp2.first--;
                    }
                }
                else{
                    ans.push_back(tp1.second);
                    ans.push_back(tp2.second);
                    
                    tp1.first--;
                    tp2.first--;
                }
                if( tp1.first > 0 )
                    pq.push(tp1);
                
                if( tp2.first > 0 )
                    pq.push(tp2);
            }
            else{
                if((l > 0) && (ans.back() != tp1.second) || (l == 0) ){
                    ans.push_back(tp1.second);
                    tp1.first--;
                }
                break;
            }
        }
        if( ans.length() < s.length() )
            return "";
        return ans;
    }
};
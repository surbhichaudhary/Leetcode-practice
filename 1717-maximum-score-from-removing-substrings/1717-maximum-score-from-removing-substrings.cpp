class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        int ans = 0 ;
        
        if( x>=y ){ //remove all "ab" first
            string lft = "";
            
            for( int i =0 ; i< s.length() ; i++ ){
                if( !stk.empty() && ( s[i] == 'b' ) && ( stk.top() == 'a' ) ){
                    ans += x;
                    stk.pop();
                    lft.pop_back();
                }
                else{ 
                    stk.push(s[i]);
                    lft.push_back(s[i]);
                }
            }
            
            stack<char> stk2;
            for( int i = 0; i < lft.size() ; i++ ){
                if( !stk2.empty() && ( stk2.top() == 'b' ) && ( lft[i] == 'a' )  ){
                    ans += y;
                    stk2.pop();
                }
                else{ 
                    stk2.push(lft[i]);
                }
            }
            
        }
        else{ // remove all "ba" first
            string lft = "";
            
            for( int i =0 ; i< s.length() ; i++ ){
                if( !stk.empty() && ( stk.top() == 'b' ) && ( s[i] == 'a' )  ){
                    ans += y;
                    stk.pop();
                    lft.pop_back();
                }
                else{ 
                    stk.push(s[i]);
                    lft.push_back(s[i]);
                }
            }
            
            stack<char> stk2;
            for( int i = 0; i < lft.size() ; i++ ){
                if( !stk2.empty() && ( stk2.top() == 'a' ) && ( lft[i] == 'b' )  ){
                    ans += x;
                    stk2.pop();
                }
                else{ 
                    stk2.push(lft[i]);
                }
            }
        }
        
        return ans;
    }
};


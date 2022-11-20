class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        stack<char> op;
        int n = s.length(), ans = 0;
        
        for( int i = 0; i < n ;i++ ){
            //neglect space
            if( s[i] == 32 ){
                continue;
            }
            //compute number
            else if( isdigit(s[i]) )
            {
                int j = i, curr = 0;
              
                while( j < n && isdigit(s[j]) ){
                    int v = ((s[j]-'0'));
                    curr *= 10;
                    curr += v;
                    j++;
                }

                stk.push(curr);
                op.push('d');
                i = j-1;
            }
            //if multiply OR divide compute it
            else if( s[i] == '*' || s[i] == '/' ){
                // compute next number to perform calculation
                int j = i+1, b = 0;
                while( j < n && s[j] == 32 ){
                    j++;
                }
                
                while( j < n && isdigit(s[j]) ){
                    int v = ((s[j]-'0'));
                    b *= 10;
                    b += v;
                    j++;
                }

                int a = stk.top();
                stk.pop();
                
                if( s[i] == '*'){
                    a *= b;
                }
                else{
                    a /= b;
                }
                
                stk.push(a);
                i = j-1;
            }
            else if( s[i] == '+' || s[i] == '-' ) 
            {
                op.push(s[i]);
            }
        }
        
        stack<int> tmp;
        while( !op.empty() ){
            if( op.top() == 'd' ){
                int a = stk.top();
                stk.pop();
                op.pop();
                
                if( !op.empty() ){
                    if( op.top() == '-' ){
                        a *= (-1);
                    }
                    else if( op.top() == '+' ){
                    }
                    op.pop();
                }
                tmp.push(a);
            }
        }
        
        while( !tmp.empty() ){
            ans += tmp.top();
            tmp.pop();
        }
        
        return ans;
        
    }
};

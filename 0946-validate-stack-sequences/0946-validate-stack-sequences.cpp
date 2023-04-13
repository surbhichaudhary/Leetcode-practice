class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0 , j = 0, n = pushed.size();
        
        while( i < n && j < n ){
            if( !s.empty() && s.top() == popped[j] ){
                s.pop();
                j++;
            }
            else{
                s.push( pushed[i] );
                i++;
            }
            if( !s.empty() && s.top() == popped[j] ){
                s.pop();
                j++;
            }
        }
        
        while( i < n ){
            s.push( pushed[i] );
            i++;
        }
        while( j < n ){
            if( !s.empty() && s.top() == popped[j] ){
                s.pop();
                j++;
            }
            else{
                break;
            }
        }
        return s.empty();
    }
};
class Solution {
public:
    
    string countOfAtoms(string formula) {
        
        string ans = "";
        int n = formula.length(), i = 0;
        map<string, int> mp;
        
        while( i < n )
        {
            //cout<<i<<" ";
            if( formula[i] == '(' ) 
            {//use stack
                stack< pair< string, int> > s;
                s.push({ "(", 0 });
                i++;
   
                while( !s.empty() ){
                    if( isupper( formula[i] )) 
                    {
                        string curr = "";
                        curr.push_back( formula[i++] );
                        int v = 1;

                        while( i < n && islower(formula[i] ) )
                        {
                            curr.push_back(formula[i]);
                            i++;
                        }
                        //find frequency
                        if( i < n && isdigit( formula[i] ) )
                        {
                            v = 0;
                            while( i<n && isdigit( formula[i] ) ){
                                v *= 10;
                                v += ( formula[i] - '0' );
                                i++;
                            }
                        }
                        
                        s.push({ curr, v });
                    }
                    //another opening
                    else if( formula[i] == '(' )
                    {
                        s.push({ "(", 0 });
                        i++;
                    }
                    //closing
                    else if( formula[i] == ')' )
                    {
                        i++;
                        int v = 1;
                        if( isdigit(formula[i]) ){
                            v = 0;
                            while( ( i < n) && isdigit(formula[i]) ){
                                v *= 10;
                                v += (formula[i] - '0' );
                                i++;
                            }
                        }
                        // multiply freq
                        stack< pair< string, int> > tmp;
                        while( s.top().first != "(" ){
                            s.top().second *= v;
                            tmp.push( s.top() );
                            s.pop();
                        }

                        s.pop();
                        // if still brackets remaining
                        if( !s.empty() ){
                            while( !tmp.empty() ){
                                s.push( tmp.top() );
                                tmp.pop();
                            }
                        }
                        // no brackets
                        else{
                            while( !tmp.empty() ){
                                mp[tmp.top().first] += tmp.top().second;
                                tmp.pop();
                            }
                        }
                            
                    }
                }
            }
            //no bracket
            else if( isupper( formula[i] ) )
            {
                //cout<<i<<" ";
                string curr = "";
                curr.push_back( formula[i++] );
                int v = 1;
      
                while( i < n && islower(formula[i] ) )
                {
                    curr.push_back(formula[i]);
                    i++;
                }
                //find repetetion
                if( i < n && isdigit( formula[i] ) )
                {
                    v = 0;
                    while( i<n && isdigit( formula[i] ) ){
                        v *= 10;
                        v += ( formula[i] - '0' );
                        i++;
                    }
                }
                mp[curr] += v;
            }
            else
            {
                i++;
            }
        }
        //store with freq
        for( auto i : mp ){
            ans += i.first;
            if( i.second > 1 ){
                ans += ( to_string(i.second) );
            }
            
        }
        
        return ans;
    }
};

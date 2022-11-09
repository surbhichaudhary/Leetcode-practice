typedef pair<string, int> si;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> dead;
        for( int i =0; i< deadends.size(); i++ ){
            dead[deadends[i]]++;
        }
        
        queue<si> pq;
        pq.push({ "0000", 0 });
        
        while( !pq.empty() ){
            int d = pq.front().second;
            string curr = pq.front().first;
            pq.pop();
            
            if( curr == target ){
                return d;
            }
            
            if( dead.count(curr) ){
                continue;
            }
            dead[curr]++;
            
            for( int i = 0 ; i < 4 ; i++ ){
                string tmp = curr;
                char c = tmp[i];
                int v = c - '0';
                //forward rotation
                v++;
                v %= 10;
                tmp[i] = v + '0';
                //cout<<tmp<<"\n";
                if( !dead.count(tmp) ){
                    pq.push({ tmp, d+1 });
                }
                
                tmp[i] = c;
                //backward rotation
                v = c-'0';
                v += 9;
                v %= 10;
                tmp[i] = v + '0';
                //cout<<tmp<<"\n";
                if( !dead.count(tmp) ){
                    pq.push({ tmp, d+1 });
                }
            }
            
        }
        return (-1);
    }
};
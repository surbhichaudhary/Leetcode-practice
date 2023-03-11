class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), i =0, j = n-1, r = 0, ac = capacityA, bc = capacityB;
        while( i <= j )
        {
            if( i == j ){
                if( ac >= bc ){
                    if( ac < plants[i] ){
                        ac = capacityA;
                        r++;
                    }
                    ac -= plants[i++];
                }
                else{
                    if( bc < plants[j] ){
                        bc = capacityB;
                        r++;
                    }
                    bc -= plants[j--];
                }
            }
            else{
                if( ac < plants[i] ){
                    ac = capacityA;
                    r++;
                }
                ac -= plants[i++];
                
                if( bc < plants[j] ){
                    bc = capacityB;
                    r++;
                }
                bc -= plants[j--];
                
            }
        }
        
        return r;
    }
};
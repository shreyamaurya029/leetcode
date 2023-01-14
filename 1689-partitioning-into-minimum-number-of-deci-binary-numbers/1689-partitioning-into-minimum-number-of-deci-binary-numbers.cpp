class Solution {
public:

    int minPartitions(string n) {
        
        int maximum = INT_MIN;
        for(auto x: n)
            maximum = max(maximum, x-'0');
        
        return maximum;
    }  
};
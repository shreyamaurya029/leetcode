class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        
        int n = s.size();
        for(int i=0; i<n; i++){
            char ch = s[i];
            mp[ch] = i;
        }
        
        vector<int>res;
        int prev = -1;
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi, mp[s[i]]);
            
            if(maxi == i){
                //partition time 
                res.push_back(maxi- prev);
                prev = maxi;
            }
        }
            
        return res;
        
    }
};
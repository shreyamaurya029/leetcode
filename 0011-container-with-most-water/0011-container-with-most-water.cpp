class Solution {
public:
    int maxArea(vector<int>& ht) {
        int j = ht.size()-1;
        int i=0;
        int ans = 0;
        while(i<j){
            ans = max(ans,min(ht[i],ht[j])*(j-i));
            if(ht[i]<ht[j]) i++;
            else j--;
        }
        
        return ans;
    }
};
class Solution {
public:
    
    bool feasible(long long mid, vector<int>&piles, long long h){
        long long total_hrs = 0;
        for(auto it: piles){
            total_hrs += (it+mid-1)/(mid);
        }
        return total_hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            long long mid = low+(high-low)/2;
            if(feasible(mid, piles,h)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
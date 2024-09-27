class Solution {
public:
    
    
    bool feasible(int capacity, vector<int>&weights, int days){
        int total = 0,day=1;
        for(auto it: weights){
            total+=it;
            if(total > capacity){  //if the total weight becomes greater than the current mid go to the next day and we keep total = it so that it is added to the next day
                total = it;
                day++;
                
                if(day>days){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
//     Example:
// Let's say weights = [3, 8, 2, 5] and the shipping capacity is 10.

// Day 1: Start with total = 0.
// Add 3: total = 3.
// Add 8: total = 3 + 8 = 11 (exceeds capacity of 10).
// Start a new day, so reset total = 8. The new day starts with the current item.
// Day 2:
// Now, total = 8 for the new day.
// Add 2: total = 8 + 2 = 10 (within capacity, so we continue).
// Add 5: total = 10 + 5 = 15 (exceeds capacity of 10).
// Start a new day, so reset total = 5.
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(feasible(mid,weights,days)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
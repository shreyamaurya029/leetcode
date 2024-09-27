class Solution {
public:
    
    int feasible(int mid,vector<int>&nums,int k){
        int total=0, n = 1;
        for(auto it: nums){
            total += it;
            if(total > mid){
                total = it;
                n++;
                
                if(n > k){
                    return false;
                }
                
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(feasible(mid,nums,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
class Solution {;
public:
    int search(vector<int>& nums, int target) {
        long long n = nums.size();
        long long low = 0, high = nums.size()-1;
        
        while(low <= high){
            long long mid = (high+low)/2; 
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] > target){
                high = mid-1;
            }
            
            else if(nums[mid] < target){
               low = mid+1;
            }
        }
        return -1;
    }
};
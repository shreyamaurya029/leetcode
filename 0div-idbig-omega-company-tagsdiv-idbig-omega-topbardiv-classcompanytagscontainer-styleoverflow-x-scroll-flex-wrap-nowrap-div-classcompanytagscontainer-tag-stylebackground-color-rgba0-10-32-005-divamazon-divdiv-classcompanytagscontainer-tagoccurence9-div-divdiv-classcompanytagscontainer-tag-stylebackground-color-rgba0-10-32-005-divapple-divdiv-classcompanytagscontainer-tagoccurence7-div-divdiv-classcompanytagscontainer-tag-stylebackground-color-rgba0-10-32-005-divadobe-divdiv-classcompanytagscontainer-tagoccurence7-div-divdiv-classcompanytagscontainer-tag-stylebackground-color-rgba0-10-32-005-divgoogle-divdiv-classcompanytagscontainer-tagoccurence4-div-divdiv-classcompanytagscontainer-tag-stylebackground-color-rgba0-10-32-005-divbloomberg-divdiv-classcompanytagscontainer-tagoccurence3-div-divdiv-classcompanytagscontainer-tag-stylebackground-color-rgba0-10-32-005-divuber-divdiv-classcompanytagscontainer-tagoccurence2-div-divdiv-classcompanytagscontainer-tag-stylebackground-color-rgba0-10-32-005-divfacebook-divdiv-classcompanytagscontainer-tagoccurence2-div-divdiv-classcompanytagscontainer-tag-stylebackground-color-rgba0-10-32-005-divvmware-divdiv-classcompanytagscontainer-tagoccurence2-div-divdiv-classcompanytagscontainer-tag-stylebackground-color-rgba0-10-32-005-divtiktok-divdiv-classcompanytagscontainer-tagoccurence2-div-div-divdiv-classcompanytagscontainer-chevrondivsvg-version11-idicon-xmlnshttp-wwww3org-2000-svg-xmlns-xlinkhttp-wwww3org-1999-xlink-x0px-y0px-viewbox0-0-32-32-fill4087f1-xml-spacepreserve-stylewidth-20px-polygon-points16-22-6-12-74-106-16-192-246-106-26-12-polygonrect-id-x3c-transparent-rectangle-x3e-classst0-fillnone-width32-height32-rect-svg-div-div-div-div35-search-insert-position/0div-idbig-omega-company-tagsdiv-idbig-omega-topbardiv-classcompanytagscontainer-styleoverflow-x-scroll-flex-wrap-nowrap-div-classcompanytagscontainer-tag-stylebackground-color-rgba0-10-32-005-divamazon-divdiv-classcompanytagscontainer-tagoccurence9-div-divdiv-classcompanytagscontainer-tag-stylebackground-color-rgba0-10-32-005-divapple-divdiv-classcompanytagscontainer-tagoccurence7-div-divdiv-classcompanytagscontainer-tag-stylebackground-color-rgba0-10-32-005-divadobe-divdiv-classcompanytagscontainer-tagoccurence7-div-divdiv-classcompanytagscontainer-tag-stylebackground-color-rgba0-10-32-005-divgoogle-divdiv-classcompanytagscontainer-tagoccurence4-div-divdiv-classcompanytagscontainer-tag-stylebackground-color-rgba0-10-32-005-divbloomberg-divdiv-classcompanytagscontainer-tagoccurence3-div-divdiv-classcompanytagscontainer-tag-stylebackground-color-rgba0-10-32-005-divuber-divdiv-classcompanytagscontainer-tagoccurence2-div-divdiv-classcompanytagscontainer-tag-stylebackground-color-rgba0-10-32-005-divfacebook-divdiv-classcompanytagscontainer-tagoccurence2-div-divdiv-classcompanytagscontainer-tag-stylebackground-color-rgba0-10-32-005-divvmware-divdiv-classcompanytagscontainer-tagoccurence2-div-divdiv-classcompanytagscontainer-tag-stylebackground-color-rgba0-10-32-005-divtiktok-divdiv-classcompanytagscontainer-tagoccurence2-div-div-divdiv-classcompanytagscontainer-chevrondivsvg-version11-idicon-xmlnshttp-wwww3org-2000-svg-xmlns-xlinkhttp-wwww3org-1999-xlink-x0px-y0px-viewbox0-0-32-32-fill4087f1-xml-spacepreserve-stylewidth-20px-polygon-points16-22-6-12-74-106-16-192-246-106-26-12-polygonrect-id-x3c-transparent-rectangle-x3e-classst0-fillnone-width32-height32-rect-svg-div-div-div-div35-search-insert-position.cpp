class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;

        if(target > nums[high]){
            return high+1;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if( nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        // observe that it would low
        return low;
    }
};
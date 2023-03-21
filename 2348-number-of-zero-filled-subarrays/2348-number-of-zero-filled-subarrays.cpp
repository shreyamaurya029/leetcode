class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int subarray = 0;
        long long count = 0;
        for(auto num : nums){
            if(num == 0)
                subarray++;
            else
                subarray = 0;
            count+=subarray;
        }
        
        return count;
    }
};
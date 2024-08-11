class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //just apply xor opration to the whole array
        int a = 0;
        for(int i=0; i<nums.size(); i++){
            a = a^nums[i];
        }
        return a;
    }
};
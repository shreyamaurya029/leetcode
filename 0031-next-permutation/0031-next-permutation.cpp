

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return;
        }

        int index=-1,element,check;
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                index = i-1;
                element = nums[i-1];
                break;
            }
        }

        if(index == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        sort(nums.begin() + index, nums.end());
        
        for(int i=n-1; i>=index; i--){
            if(nums[i] == element){
                check = i+1;
                break;
            }
        }
        
        reverse(nums.begin() + index, nums.begin() + check);
        reverse(nums.begin() + index, nums.begin() + check+1);
    }
};
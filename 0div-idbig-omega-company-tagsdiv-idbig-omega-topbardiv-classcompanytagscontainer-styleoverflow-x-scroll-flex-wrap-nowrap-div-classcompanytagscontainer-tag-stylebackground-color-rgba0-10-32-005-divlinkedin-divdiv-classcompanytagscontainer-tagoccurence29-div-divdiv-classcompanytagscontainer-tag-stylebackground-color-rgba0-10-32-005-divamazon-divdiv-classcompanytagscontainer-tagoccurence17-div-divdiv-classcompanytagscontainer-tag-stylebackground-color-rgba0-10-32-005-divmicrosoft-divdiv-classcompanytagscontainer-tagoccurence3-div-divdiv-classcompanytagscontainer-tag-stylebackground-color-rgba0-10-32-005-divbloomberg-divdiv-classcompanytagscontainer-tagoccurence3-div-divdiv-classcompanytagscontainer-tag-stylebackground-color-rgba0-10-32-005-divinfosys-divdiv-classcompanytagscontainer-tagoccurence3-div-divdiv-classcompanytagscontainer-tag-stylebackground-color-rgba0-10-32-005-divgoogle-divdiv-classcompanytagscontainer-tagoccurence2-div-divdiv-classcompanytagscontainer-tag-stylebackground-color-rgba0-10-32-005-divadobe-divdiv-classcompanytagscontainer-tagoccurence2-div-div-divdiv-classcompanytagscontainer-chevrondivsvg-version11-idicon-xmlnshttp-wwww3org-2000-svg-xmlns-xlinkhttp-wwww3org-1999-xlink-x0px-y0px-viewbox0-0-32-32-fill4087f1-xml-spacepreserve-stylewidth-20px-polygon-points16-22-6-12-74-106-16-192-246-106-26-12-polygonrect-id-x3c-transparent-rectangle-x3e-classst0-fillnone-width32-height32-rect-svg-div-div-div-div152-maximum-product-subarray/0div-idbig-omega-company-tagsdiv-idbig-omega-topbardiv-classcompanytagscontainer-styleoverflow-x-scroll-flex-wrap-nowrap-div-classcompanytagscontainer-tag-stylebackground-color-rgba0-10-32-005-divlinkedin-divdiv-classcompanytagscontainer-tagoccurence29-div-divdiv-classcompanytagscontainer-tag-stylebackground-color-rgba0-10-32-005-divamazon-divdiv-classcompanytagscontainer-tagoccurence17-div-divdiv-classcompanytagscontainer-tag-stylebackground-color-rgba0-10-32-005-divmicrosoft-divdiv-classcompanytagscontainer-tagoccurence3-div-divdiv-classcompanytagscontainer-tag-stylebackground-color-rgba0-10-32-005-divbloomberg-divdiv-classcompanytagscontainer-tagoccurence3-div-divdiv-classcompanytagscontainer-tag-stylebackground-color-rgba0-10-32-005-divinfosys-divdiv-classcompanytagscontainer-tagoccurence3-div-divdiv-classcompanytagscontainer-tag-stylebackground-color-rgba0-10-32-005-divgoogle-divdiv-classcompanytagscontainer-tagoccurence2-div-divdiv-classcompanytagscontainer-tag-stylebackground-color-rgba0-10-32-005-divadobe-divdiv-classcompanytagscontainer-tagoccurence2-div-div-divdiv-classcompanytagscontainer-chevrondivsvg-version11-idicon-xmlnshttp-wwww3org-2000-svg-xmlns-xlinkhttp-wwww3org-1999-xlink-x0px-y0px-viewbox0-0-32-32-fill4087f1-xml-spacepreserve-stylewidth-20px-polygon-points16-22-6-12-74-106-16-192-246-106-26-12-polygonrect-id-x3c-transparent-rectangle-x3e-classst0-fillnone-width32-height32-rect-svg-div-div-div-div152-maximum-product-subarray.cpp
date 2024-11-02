class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int res=1;
        for(int i=0; i<nums.size(); i++){
            res*=nums[i];
            maxi = max(maxi,res);
            if(res==0){
                res=1;
            }
        }

        res=1;

        for(int i=n-1; i>=0;i--){
            res*=nums[i];
            maxi = max(maxi,res);
            if(res==0){
                res=1;
            }
        }

        return maxi;
    }
};
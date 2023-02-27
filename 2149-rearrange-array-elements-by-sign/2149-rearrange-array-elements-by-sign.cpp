class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
      vector<int> res(n,0);
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                res[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                res[indexneg] = num;
                indexneg += 2;
            }
        }
        return res;
    }
};
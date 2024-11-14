class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int zeroCount = 0, l = 0;
        // int maxLen = 0;
        // for( int r = 0 ; r < A.size() ; ++r ) {
        //     if( A[ r ] == 0 ) ++zeroCount;
        //     while( zeroCount > K ) {
        //         if( A[ l ] == 0 ) --zeroCount;
        //         ++l;
        //     }
        //     maxLen = max( maxLen, r - l + 1 );
        // }
        // return maxLen;
        int n = nums.size();
        int cnt = 0,i = 0;
        int maxLen = 0;
        for(int j=0; j<n; j++){
            if(nums[j] == 0){
                cnt++;
            }
            while(cnt > k){
                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            
        }
        return maxLen;
    }
};